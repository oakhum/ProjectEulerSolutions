#include <stdio.h>

int main() {
	int fa = 1;
	int fb = 2;
	int sum = 2;
	
	while (fa + fb <= 4000000) {
		fb = fa + fb;
		fa = fb - fa;
		if (fb % 2 == 0) sum += fb;
	}
	
	printf("%d\n", sum);
}