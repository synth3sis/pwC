#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define TRUE  1
#define FALSE 0
#define version "1.3.1"

int hreq = 0;

void help() {
	if (hreq == 0) {
		printf("Usage:\n");
		printf("       ./pwC [length] [num of key]\n\n");
		printf("Options:\n");
		printf("       --human, -H    produces keys using only letters and numbers\n");
		printf("       --help, -h     print this help message and exit\n");
	} else if (hreq == 1) {
		printf("pwC version: %s\n", version);
	} else if (hreq == 2) {
		printf("Author:  Synthesis\n");
		printf("Contact: synthesis77@protonmail.com\n\n");
		printf("pwC version: %s\n\n", version);
		printf("Description:\n");
		printf("    pwC is a simple key generation, written in C.\n");
		printf("    His purpose is to be fast and reliable\n");
	}
}


// Returns	TRUE if parameter is an is_integer
// 			FALSE if parmater is a string
int is_integer(char *argv[]) {
	if (atoi(argv) > 0)
		return TRUE;
	else
		return FALSE;
}

int main(int argc, char *argv[]) {
	char dictionary[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789.::------_###@+!!!!^???$$$$%%&&&&==abcdefghijklmnopqrstuvwxyz123456789123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char humanread[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	int dic_len = strlen(dictionary) - 1;
	int hum_len = strlen(humanread) - 1;

	int length = 16;
	int num = 1;

	bool human_flag = FALSE;

	for (int i = 0; i < argc; i++) {
		if (!is_integer(argv[i])) {
			if (strcmp("--help", argv[i]) == 0 || strcmp("-h", argv[i]) == 0) {
				help(); return 1;
			} else if (strcmp("--human", argv[i]) == 0 || strcmp("-H", argv[i]) == 0) {
				human_flag = TRUE;
			} else if (strcmp("--version", argv[i]) == 0 || strcmp("-v", argv[i]) == 0) {
				hreq = 1; help(); return 1;
			} else if (strcmp("--about", argv[i]) == 0 || strcmp("-a", argv[i]) == 0) {
				hreq = 2; help(); return 1;
			}
		}
	}

	if (argc == 2) {
		if (is_integer(argv[1])) {
			length = strtol(argv[1], NULL, 10);
		} else {
			length = 16;
		}
	} else if (argc == 3) {
		if (is_integer(argv[2])) {
			length = strtol(argv[1], NULL, 10);
			num = strtol(argv[2], NULL, 10);
		} else {
			help(); return 1;
		}
	} else if (argc > 3) {
		if (is_integer(argv[1]) && is_integer(argv[2])) {
	        length = strtol(argv[1], NULL, 10);
	        num = strtol(argv[2], NULL, 10);
			human_flag = TRUE;
		} else {
			help(); return 1;
		}
	}

	// printf("length = %d\nnum    = %d\nhuman  = %d\n", length, num, human_flag

    /* Seed number for rand() */
    srand((unsigned int) time(0) + getpid());

	int temp = 0;
    while(num--)
    {
        temp = length;

		switch (human_flag) {
			case TRUE:
	        while(temp--) {
    	        printf("%c", humanread[(rand() % hum_len)]);
	       	    srand(rand());
       		}
			break;
			case FALSE:
            while(temp--) {
				printf("%c", dictionary[(rand() % dic_len)]);
                srand(rand());
            }
			break;
		}
 		printf("\n");
        temp = length;
    }

    return EXIT_SUCCESS;
}
