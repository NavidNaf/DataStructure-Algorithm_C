#include <stdio.h>

int binSearch(int high, int low, int ara[], int x)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (ara[mid] == x)
        return mid;
    else if (ara[mid] > x)
        return binSearch(mid - 1, low, ara, x);
    else
        return binSearch(high, mid + 1, ara, x);
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

    int low, high, mid;
    low = 0;
    high = n - 1;
    int valuetofind;
    printf("Find: ");
    scanf("%i", &valuetofind);
    int result = binSearch(high, low, ara, valuetofind);
    if (result == -1)
        printf("Not Found.");
    else
        printf("Value %i at %i", ara[result], result + 1);
}
