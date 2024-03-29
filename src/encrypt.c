/*
* FILE          : encrypt.c
* PROJECT       : SENG2030-20W-ince-a
* PROGRAMMER    : Abdullah Ince
* FIRST VERSION : 2021 - 02 - 07
* DESCRIPTION   : This is program used to demonstrate knowlodge of Linux envirenment with 
*				writing an encrypting / decrypting utility for Linux. This utility will take any ASCII file
*				and encrypt it in such a way that its contents are not readable – until they are decrypted by the utility.
*/
#include "../inc/encrypt.h"

void encrypt_it(FILE *f_in, FILE *f_out, const int size)
{

	char line[size];
	int outChar;
	int hex1;
	int hex2;

	while (fgets(line, size, f_in) != NULL)
	{
		for (int i = 0; i < strlen(line); ++i)
		{
			// If the character is a <tab> then simply transform it into the output character sequence TT.
			if (line[i] == '\t')
			{
				fprintf(f_out, "TT");
			}
			else if (line[i] == '\n' || line[i] == '\r')
			{
				fprintf(f_out, "%c", line[i]);
			}
			else
			{
				// Take the ASCII code for the input character and subtract a value of 16 from
				outChar = line[i] - 16;
				if (outChar < 32) // check to resultoutChar value is less than 32.
				{
					outChar += 144;
					outChar -= 32;
				}
				hex2 = outChar % 16;
				hex1 = outChar / 16;
				if (hex1 <= 9)
				{
					hex1 = '0' + hex1;
				}
				else
				{
					hex1 = 'A' + hex1 - 10;
				}
				if (hex2 <= 9)
				{
					hex2 = '0' + hex2;
				}
				else
				{
					hex2 = 'A' + hex2 - 10;
				}
				fprintf(f_out, "%c%c", hex1, hex2);
			}
		}
	}
}

void decrypt_it(FILE *f_in, FILE *f_out, const int size)
{

	char line[size];
	int outChar;

	while (fgets(line, size, f_in) != NULL)
	{
		for (int i = 0; i < strlen(line); ++i)
		{
			if (line[i] == '\n' || line[i] == '\r')
			{
				fprintf(f_out, "%c", line[i]);
			}
			else if (i + 1 < strlen(line))
			{
				if (line[i] == 'T' && line[i + 1] == 'T')
				{
					fprintf(f_out, "\t");
				}
				else
				{
					if (line[i] >= '0' && line[i] <= '9')
					{
						outChar = 16 * (line[i] - '0');
					}
					else if (line[i] >= 'A' && line[i] <= 'F')
					{
						outChar = 16 * (line[i] - 'A' + 10);
					}
					if (line[i + 1] >= '0' && line[i + 1] <= '9')
					{
						outChar += (line[i + 1] - '0');
					}
					else if (line[i + 1] >= 'A' && line[i + 1] <= 'F')
					{
						outChar += (line[i + 1] - 'A' + 10);
					}
					outChar += 16;
					if (outChar > 127)
					{
						outChar -= 144;
						outChar += 32;
					}
					fprintf(f_out, "%c", outChar);
				}
				i++;
			}
		}
	}
}
