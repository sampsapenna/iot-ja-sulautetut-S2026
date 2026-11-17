#include <stdio.h>


int main(void)
{
    printf("Print primes between 0 and 1000000\n");

    for (int i = 0; i <= 1000000; i++)
    {
        int ceiling = i / 2;
        int j = 2;
        for (; j <= ceiling; j++)
        {
            if (i % j == 0) {
                // printf("%d is not a prime, divides by %d.\n", i, j);
                break;
            }
        }
        if (j > ceiling) {
            printf("%d is a prime, doesn't divide with by anything.\n", i);
        }
    }

    printf("Execution finished.\n");

    return 0;
}
