#include <stdio.h>
#include <time.h>

/* Algorithm 1: AR(n, c) */
void AR(int n, unsigned long long *c)
{
    if (n > 0)
    {
        (*c)++;

        AR(n - 1, c);
        AR(n - 1, c);
    }
}

/* Algorithm 2: F(n) */
unsigned long long F(int n)
{
    if (n <= 1)
        return 1;

    return F(n - 1) + F(n - 2);
}

int main(void)
{
    int values[] = {10, 20, 30};
    int i, n;

    unsigned long long c, result;
    clock_t start;
    double timeAR, timeF;

    printf("RECURSIVE ALGORITHM PERFORMANCE\n");
    printf("================================\n");

    for (i = 0; i < 3; i++)
    {
        n = values[i];

        /* Test AR */
        c = 0;

        start = clock();
        AR(n, &c);
        timeAR = (double)(clock() - start) / CLOCKS_PER_SEC;

        /* Test F */
        start = clock();
        result = F(n);
        timeF = (double)(clock() - start) / CLOCKS_PER_SEC;

        printf("\nn = %d\n", n);
        printf("AR calls: %llu\n", c);
        printf("AR time: %.6f seconds\n", timeAR);
        printf("F(n): %llu\n", result);
        printf("F time: %.6f seconds\n", timeF);
    }

    return 0;
}
