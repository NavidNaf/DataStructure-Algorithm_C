#include <stdio.h>

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
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (ara[mid] == valuetofind)
        {
            break;
        }
        else if (ara[mid] > valuetofind)
        {
            high = mid - 1;
        }
        else if (ara[mid] < valuetofind)
        {
            low = mid + 1;
        }
    }
    if (low > high)
        printf("Not Found.");
    else
        printf("Found %i at %i", ara[mid], mid + 1);
}