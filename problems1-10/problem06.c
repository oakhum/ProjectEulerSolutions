#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int n, sumOfSquares, squareOfSum;
	if (argc < 2) {
		printf("Enter a number for finding the difference between the sum of the squares of the first nth natural numbers and the square of the sum.\n");
		return 0;
	} else if ((n = atoi(argv[1])) > 0) {
		sumOfSquares = ( ( 2 * pow(n, 3) ) + ( 3 * pow(n, 2) ) + n ) / 6;
		squareOfSum = pow( ( ( n * ( n + 1 ) ) / 2 ), 2);
		printf("%20s%d\n", "Number entered: ", n);
		printf("%20s%d\n", "Square of sum: ", squareOfSum);
		printf("%20s%d\n", "Sum of squares: ", sumOfSquares);
		printf("%20s%d\n", "Difference: ", squareOfSum - sumOfSquares);
		return 0;
	} else {
		printf("Enter a positive number.\n");
		return 0;
	}
}
