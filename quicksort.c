#include <stdio.h>
#include <stdlib.h>

int partition(int A[], int low, int high)
{
    int pivot, i, j, temp;
    pivot = A[high];
    i = low - 1;
    for (j = low; j < high; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    temp = A[high];
    A[high] = A[i + 1];
    A[i + 1] = temp;

    return (i + 1);
}

void quickSort(int A[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int p = partition(A, low, high);
    quickSort(A, low, p - 1);
    quickSort(A, p + 1, high);
}

int main(void)
{
    int n;
    printf("Size: ");
    scanf("%i", &n);
    int ara[n];
    for (int i = 0; i < n; i++)
    {
        printf("Value %i: ", i + 1);
        scanf("%i", &ara[i]);
    }
    quickSort(ara, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%i ", ara[i]);
    }
}
