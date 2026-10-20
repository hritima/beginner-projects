/* 
 * Project5.c
 * Name: Hritima Thapa Magar
 * netid: hritima
 * Program description: Encrypts or decrypts a string by adding or subracting a shift value from each character
 */



#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 50

/* Functions */
int my_strlen(char *str);
int my_strcmp(char *str, char *str2);
int encrypt_string(char *str, int shift);
int decrypt_string(char *str, int shift);
 

/* Main function: validates the command-line arguments, copies the input string into character array, then encrypts/decrypts it. */
int main(int argc, char *argv[])
{
	if (argc < 4) {
		printf("Invalid option\n");
		return 0;
	}
	
	/* Checks which option the user entered */
	int is_encrypt = (my_strcmp(argv[1], "-e") == 0);
        int is_decrypt = (my_strcmp(argv[1], "-d") == 0);
	
	/* Only -e and -d options are accepted */
	if (!is_encrypt && !is_decrypt) {
		printf("Invalid option\n");
		return 0;
	}

	/* Converting the shift value to an integer. */
	int shift = atoi(argv[2]);

	/* Allocating space for maximum 51 characters including the null terminator. */
	char text[MAX_STR_LEN + 2];
	char *dst = text;
	char *limit = text + MAX_STR_LEN +1;
	int i;
	
	for (i = 3; i < argc; i++) {
		char *src = argv[i];

		if (i > 3 && dst < limit)
			*dst++ = ' ';

		while (*src != '\0' && dst < limit) {
			*dst = *src;
			dst++;
			src++;
		}
	}
	
	/* Terminating the copied string. */
	*dst = '\0';

	my_strlen(text); 		

	/* tEncrypt ot decrypt based on requested operation */
	if (is_encrypt) { 
		encrypt_string(text, shift);
	} else {
		decrypt_string(text, shift);
	}


	/* Print the result */
	printf("%s\n", text);
	
	return 0;
}

	
/* Returns the length of str, or 0 of str is NULL */
int my_strlen(char *str)
{
	int len = 0;
	
	if (str == NULL)
		return 0;
	
	while (*str != '\0' && *str != '\n') {
		len++;
		str++;
		
		/* Prints an error if the length exceeds MAX_STR_LEN */
		if (len > MAX_STR_LEN) {
			printf("String too long\n");
			exit(EXIT_FAILURE);
		}
	}
	
	return len;
}

/* Compares two strings and return 0 if equal, 1 if str1 is greater, or -1 if it is smaller */
int my_strcmp(char *str1, char *str2)
{
	if (str1 == NULL && str2 == NULL)
		return 0;
	if (str1 == NULL)
		return -1;
        if (str2 == NULL)
		return 1;
	
	while (*str1 != '\0' && *str1 == *str2) {
		str1++;
                str2++;
	}

	if (*str1 == *str2)
		return 0;
	return (*str1 > *str2) ? 1 : -1;
}


/* encrypt_strings: adds shift to every character of str in place */

int encrypt_string(char *str, int shift)
{
	/* Returns 1 if success, 0 if str in NULL */
	if (str == NULL)
		return 0;

	while (*str != '\0' && *str != '\n') {
		*str += shift;
		str++;
	}
	
	return 1;
}		

/* decrypt_strings: reduces shift from every character of str in place */

int decrypt_string(char *str, int shift)
{
        /* Returns 1 if success, 0 if str in NULL */
        if (str == NULL)
                return 0;

        while (*str != '\0' && *str != '\n') {
                *str -= shift;
                str++;
        }

        return 1;
}
