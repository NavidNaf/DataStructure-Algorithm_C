#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int left, int mid, int right)
{
    int sizeL = mid - left + 1;
    int sizeR = right - mid;
    int Left[sizeL];
    int Right[sizeR];

    for (int i = 0; i < sizeL; i++)
    {
        Left[i] = A[left + i];
    }
    for (int i = 0; i < sizeR; i++)
    {
        Right[i] = A[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < sizeL && j < sizeR)
    {
        if (Left[i] <= Right[j])
        {
            A[k] = Left[i];
            i++;
        }
        else
        {
            A[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < sizeL)
    {
        A[k] = Left[i];
        i++;
        k++;
    }
    while (j < sizeR)
    {
        A[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
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
    for (int i = 0; i < n; i++)
    {
        printf("%i ", ara[i]);
    }
    mergeSort(ara, 0, n - 1);//1 less than the total according to the index
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i ", ara[i]);
    }
}