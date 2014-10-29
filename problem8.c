#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_DIGITS 10000

int main(int argc, char *argv[]) {
	FILE *file;
	char number[MAX_NUM_DIGITS];
	int i, j, numAdjDigits, len;
	unsigned long long currentProduct, maxProduct;
	
	if (argc < 3) {
		printf("Input a file to read from and the number of adjacent digits to process.\n");
		return 0;
	} else if ((numAdjDigits = atoi(argv[2])) < 1) {
		printf("Cannot process zero or fewer digits.\n");
		return 0;
	} else if ((file = fopen(argv[1], "r")) == NULL) { 
		printf("Cannot open the specified file.\n");
		return 1;
	}
	
	fgets(number, MAX_NUM_DIGITS, file);
	len = strlen(number);
	i = 0;
	while (number[i] == '0' && number[i++] != '\0') ; // skip any leading zeroes
	currentProduct = number[i++] - '0';
	maxProduct = 0;
	j = 1;
	while (i < len) {
		if (number[i] == '0') {
			i++;
			currentProduct = number[i++] - '0';
			j = 1;
			continue;
		} else if (j < numAdjDigits) {
			currentProduct *= number[i++] - '0';
			j++;
		} else {
			currentProduct = currentProduct * (number[i] - '0') / (number[i++ - numAdjDigits] - '0');
		}
		
		if (currentProduct > maxProduct)
			maxProduct = currentProduct;
	}
	printf("%llu\n", maxProduct);
	
	free(number);
	fclose(file);
	
	return 0;
}