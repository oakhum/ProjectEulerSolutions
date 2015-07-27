#include <stdio.h>
#include <time.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: problem10 <integer>");
        return 0;
    }

    int n = atoi(argv[1]);
    if (n < 3) {
        printf("0\n");
        return 0;
    }

    unsigned long sum_of_primes = 2;
    int i;
    for (i = 3; i < n; i += 2) {
        int j;
        for (j = 3; j < (i/2 + 1); j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (j >= (i/2 + 1)) {
            sum_of_primes += i;
        } else {
            continue;
        }
    }

    printf("Sum of all primes below %d: %lu\n", n, sum_of_primes);
    printf("Execution time in seconds: %d\n", clock()/CLOCKS_PER_SEC);
    return 0;
}
