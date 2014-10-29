#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int result = 0;
	int num = 0;
	
	if (argc < 2) {
		printf("Enter a number for prime checking.\n");
		return 0;
	}
	
	num = atol(argv[1]);
	if (isPrime(num))
		printf("%ld is prime.\n", num);
	else
		printf("%ld is not prime.\n", num);
	
	return 0;
}

int isPrime(unsigned long n) {
	int i = 2;
	while (i <= n / 2)
		if (n % i++ == 0) return 0;
	return 1;
}