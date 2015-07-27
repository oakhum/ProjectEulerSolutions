#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int *primes;
	int i, j, desiredPrime, currentNumber;
	
	if (argc < 2) {
		printf("Enter the nth prime number you wish to find.\n");
		return 0;
	} else if ((desiredPrime = atoi(argv[1])) < 1) {
		printf("Only positive integers are accepted.\n");
		return 0;
	}
	
	primes = (int *)calloc(desiredPrime, sizeof(int));
	primes[0] = 2;
	// initialize remaining array values to -1
	i = 1;
	while (i < desiredPrime) primes[i++] = -1;
	
	i = 1; 
	currentNumber = 3;
	while (i < desiredPrime) {
		for (j = 0; primes[j] > 0; j++) {
			if (currentNumber % primes[j] == 0) {
				currentNumber++;
				break;
			}
		}
		if (primes[j] < 0) {
			primes[j] = currentNumber;
			i++;
		}
	}
	
	printf("Prime number %d is %d.\n", desiredPrime, primes[desiredPrime - 1]);
	
	// crap i forgot the most important step - cleaning up after yourself
	free(primes);
	return 0;
}