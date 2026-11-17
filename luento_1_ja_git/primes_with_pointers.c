#include <stdio.h>

void check_if_prime(int x, int *y)
{
    int ceiling = x / 2;
    for (;;)
    {
        *y = *y + 1;

        if (*y > ceiling)
            return;

        if (x % *y == 0)
        {
            // printf("%d is not a prime, divides by %d.\n", i, j);
            break;
        }
    }
}

int main(void)
{
    printf("Print primes between 0 and 100000\n");

    for (int i = 0; i <= 100000; i++)
    {
        int ceiling = i / 2;
        int j = 2;
        check_if_prime(i, &j);
        if (j > ceiling)
        {
            printf("%d is a prime, doesn't divide with by anything.\n", i);
        }
    }

    printf("Execution finished.\n");

    return 0;
}
