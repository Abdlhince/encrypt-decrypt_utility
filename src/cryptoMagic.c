#include <stdio.h>
#include <string.h>
#include "../inc/encrypt.h"

int main(int argc, char *argv[])
{

	FILE *in_file;
	FILE *out_file;
	char in_fileName[MAX_CHAR_EN];
	char out_fileName[MAX_CHAR_EN];
	int encrypt = 0;
	int decrypt = 0;

	if (argc == 3)
	{
		if (strcmp(argv[1], "-encrypt") == 0)
		{
			encrypt = 1;
		}
		else if (strcmp(argv[1], "-decrypt") == 0)
		{
			decrypt = 1;
		}
		strcpy(in_fileName, argv[2]);
	}
	else if (argc == 2)
	{
		strcpy(in_fileName, argv[1]);
		encrypt = 1;
	}

	if (encrypt != 1 && decrypt != 1)
	{
		fprintf(stderr, "%s\n", "usage: cryptoMagic [-encrypt] [-decrypt] inputFile");
		return -1;
	}
	//  validate output file extension
	if (encrypt == 1)
	{
		strcpy(out_fileName, in_fileName);
		if (strchr(out_fileName, '.') != NULL)
		{
			char *ptr = out_fileName;
			while (strchr(ptr, '.') != NULL)
			{
				ptr++;
			}
			*ptr = '\0';
			strcat(out_fileName, "crp");
		}
		else
		{
			strcat(out_fileName, ".crp");
		}
	}
	else if (decrypt == 1)
	{
		strcpy(out_fileName, in_fileName);
		if (strchr(out_fileName, '.') != NULL)
		{
			char *ptr = out_fileName;
			while (strchr(ptr, '.') != NULL)
			{
				ptr++;
			}
			*ptr = '\0';
			strcat(out_fileName, "txt");
		}
		else
		{
			strcat(out_fileName, ".txt");
		}
	}

	in_file = fopen(in_fileName, "r");
	if (in_file == NULL)
	{
		fprintf(stderr, "%s\n", "Error opening input file");
		return -1;
	}

	out_file = fopen(out_fileName, "w");
	if (out_file == NULL)
	{
		fprintf(stderr, "%s\n", "Error opening output file");
		return -1;
	}

	if (encrypt == 1)
	{
		encrypt_it(in_file, out_file, MAX_CHAR_EN);
	}
	else if (decrypt == 1)
	{
		decrypt_it(in_file, out_file, MAX_CHAR_DE);
	}

	fclose(in_file);
	fclose(out_file);
}
