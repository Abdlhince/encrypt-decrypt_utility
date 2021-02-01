#ifndef _ENCRYPT_H_
#define _ENCRYPT_H_

#include <stdio.h>
#include <string.h>

#define MAX_CHAR_EN 120
#define MAX_CHAR_DE 255


void encrypt_it(FILE *f_in, FILE *f_out, const int size);
void decrypt_it(FILE *f_in, FILE *f_out, const int size);


#endif
