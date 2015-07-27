#include <stdio.h>
#include <math.h>

int main() {
	int thirdDigit, numPrefix, currentPalindrome, largestPalindrome = 9009;
	
	for (numPrefix = 10; numPrefix < 100; numPrefix++) {
		for (thirdDigit = 0; thirdDigit < 10; thirdDigit++) {
			currentPalindrome = (numPrefix * 1000) + (thirdDigit * 100) + (reverseInt(numPrefix));
			if (isValidPalindrome(currentPalindrome)) {
				largestPalindrome = currentPalindrome;
			}
		}
	}
	for (numPrefix = 100; numPrefix < 1000; numPrefix++) {
		currentPalindrome = (numPrefix * 1000) + (reverseInt(numPrefix));
		if (isValidPalindrome(currentPalindrome)) {
			largestPalindrome = currentPalindrome;
		}
	}
}

int reverseInt(int n) {
	int digit, result = 0;
	
	while (n > 0) {
		digit = n % 10;
		result = result * 10 + digit;
		n /= 10;
	}
	
	return result;
}

int isValidPalindrome(int p) {
	int factor;
	
	for (factor = 100; factor <= (int) floor(sqrt(p)); factor++) {
		if (p % factor == 0 && p / factor > 99 && p / factor < 1000) {
			printf("%d x %d = %d\n", factor, p / factor, p);
			return 1;
		}
	}
	
	return 0;
}