/*
* FILE          : encrypt.h
* PROJECT       : SENG2030-20W-ince-a
* PROGRAMMER    : Abdullah Ince
* FIRST VERSION : 2021 - 02 - 07
* DESCRIPTION   : This is program used to demonstrate knowlodge of Linux envirenment with 
*				writing an encrypting / decrypting utility for Linux. This utility will take any ASCII file
*				and encrypt it in such a way that its contents are not readable – until they are decrypted by the utility.
*/
#ifndef _ENCRYPT_H_
#define _ENCRYPT_H_

#include <stdio.h>
#include <string.h>

#define MAX_CHAR_EN 120
#define MAX_CHAR_DE 255

void encrypt_it(FILE *f_in, FILE *f_out, const int size);
void decrypt_it(FILE *f_in, FILE *f_out, const int size);

#endif
