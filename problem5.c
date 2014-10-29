#include <stdio.h>

int main() {
	int currentNum = 20;
	
	while (!validNum(currentNum)) currentNum += 20;
	
	printf("%d\n", currentNum);
	
	return 0;
}

int validNum(int n) {
	int divisor;
	for (divisor = 2; divisor < 20; divisor++)
		if (n % divisor != 0) return 0;
	return 1;
}