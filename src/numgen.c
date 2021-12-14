#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 10000000000

int main(void) {
	srand(time(NULL));

	long int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() * rand();
	}

	long int res = 1;
	for (int i = 0; i < 10; i++) {
		res = res * arr[i];
	}

	if (res < 0) {
		res = res * (-1);
	}

	while (res < LIMIT) {
		res = res * 2;
	}

	if (res < 0) {
		res = res * (-1);
	}

	printf("%li\n", res % LIMIT);


	return 0;
}
