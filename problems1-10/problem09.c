#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int input, n, m, foundTriplet;
	int a, b, c;
	if (argc < 2) {
		printf("A Pythagorean triplet is a set of three natural numbers, a < b < c, for which a^2 + b^2 = c^2.\n");
		printf("Enter a number to check if there exists a Pythagorean triplet for which a + b + c = n.\n");
		printf("If it exists, this program will also output the product abc.\n");
		return 0;
	} else if ((input = atoi(argv[1])) < 1) {
		printf("n must be positive.\n");
		return 0;
	}
	
	foundTriplet = 0;
	n = 1; m = 2;
	while (!foundTriplet && (((2 * pow(n, 2)) + (3 * n) + 1) <= input)) {
		while (((2 * pow(m, 2)) + (2 * m * n)) < input) m++;
		if (((2 * pow(m, 2)) + (2 * m * n)) == input)
			foundTriplet = 1;
		else {
			n++; 
			m = n + 1;
		}
	}
	
	if (foundTriplet) {
		a = pow(m, 2) - pow(n, 2);
		b = 2 * m * n;
		c = pow(m, 2) + pow(n, 2);
		printf("There does exist a Pythagorean triplet such that a + b + c = %d.\n", input);
		printf("a = %d, b = %d, c = %d, abc = %d\n", a, b, c, a * b * c);
		return 0;
	} else {
		printf("There is no such Pythagorean triplet such that a + b + c = %d.\n", input);
		return 0;
	}
}