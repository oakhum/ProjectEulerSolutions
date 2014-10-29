#include <stdio.h>

int main() {
	int n = 0;
	int sum = 0;
	
	while (n < 1000) {
		if (n % 3 == 0 || n % 5 == 0)
			sum += n;
		n++;
	}
	
	printf("%d\n", sum);
	
	return 0;
}