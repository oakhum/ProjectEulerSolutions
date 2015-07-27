#include <stdio.h>

unsigned long long getNextPrime(unsigned long long n);
int isPrime(unsigned long long n);

int main() {
	unsigned long long currentPrime = 2;
	unsigned long long largestPrimeFactor = 2;
	unsigned long long fuckHugeNumber = 600851475143;
	
	// modulo operator seems to be fucked; implementing it manually
	printf("Prime factors of %llu:\n", fuckHugeNumber);
	while (fuckHugeNumber > 1) {
		if (fuckHugeNumber % currentPrime == 0) {
			printf("%llu\n", currentPrime);
			largestPrimeFactor = currentPrime;
			fuckHugeNumber /= currentPrime;
		} else {
			currentPrime = getNextPrime(currentPrime);
		}
	}

	return 0;
}

unsigned long long getNextPrime(unsigned long long n) {
	while (!isPrime(++n)) ;
	return n;
}

int isPrime(unsigned long long n) {
	unsigned long long i = 2;
	while (i <= n / 2)
		if (n % i++ == 0) return 0;
	return 1;
}