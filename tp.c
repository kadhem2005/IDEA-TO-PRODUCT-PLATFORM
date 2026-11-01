#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

/* Algorithm 1: Nested-loop sorting - O(n^2) */
void algorithm1(int T[], int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (T[j] <= T[i])
            {
                temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
        }
    }
}

/* Merge two sorted sections */
void merge(int T[], int temp[], int left, int middle, int right)
{
    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right)
    {
        if (T[i] <= T[j])
            temp[k++] = T[i++];
        else
            temp[k++] = T[j++];
    }

    while (i <= middle)
        temp[k++] = T[i++];

    while (j <= right)
        temp[k++] = T[j++];

    for (i = left; i <= right; i++)
        T[i] = temp[i];
}

/* Recursive merge sort - O(n log n) */
void mergeSort(int T[], int temp[], int left, int right)
{
    int middle;

    if (left < right)
    {
        middle = left + (right - left) / 2;

        mergeSort(T, temp, left, middle);
        mergeSort(T, temp, middle + 1, right);

        merge(T, temp, left, middle, right);
    }
}

/* Check whether the array is sorted */
int isSorted(int T[], int n)
{
    int i;

    for (i = 1; i < n; i++)
    {
        if (T[i] < T[i - 1])
            return 0;
    }

    return 1;
}

int main(void)
{
    int sizes[] = {1000, 3000, 5000, 10000};
    int numberOfSizes = 4;
    int original[MAX_SIZE];
    int A[MAX_SIZE];
    int B[MAX_SIZE];
    int temp[MAX_SIZE];
    int n, i, test;

    double start, time1, time2;

    srand((unsigned int)time(NULL));

    printf("SORTING ALGORITHM COMPARISON\n");
    printf("============================\n");

    for (test = 0; test < numberOfSizes; test++)
    {
        n = sizes[test];

        /* Generate random numbers */
        for (i = 0; i < n; i++)
            original[i] = rand() % 100000;

        /* Copy the same input for both algorithms */
        for (i = 0; i < n; i++)
        {
            A[i] = original[i];
            B[i] = original[i];
        }

        /* Test Algorithm 1 */
        start = (double)clock() / CLOCKS_PER_SEC;

        algorithm1(A, n);

        time1 = (double)clock() / CLOCKS_PER_SEC - start;

        /* Test Algorithm 2 */
        start = (double)clock() / CLOCKS_PER_SEC;

        mergeSort(B, temp, 0, n - 1);

        time2 = (double)clock() / CLOCKS_PER_SEC - start;

        /* Display results */
        printf("\nArray size: %d\n", n);

        printf("Algorithm 1 (O(n^2)):     %.6f seconds\n", time1);
        printf("Algorithm 2 (O(n log n)): %.6f seconds\n", time2);

        printf("Algorithm 1 correct: %s\n",
               isSorted(A, n) ? "YES" : "NO");

        printf("Algorithm 2 correct: %s\n",
               isSorted(B, n) ? "YES" : "NO");
    }

    return 0;
}
