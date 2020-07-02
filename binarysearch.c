#include <stdio.h>

int main(void)
{
    int low, high, mid;
    do
    {
        printf("Low: ");
        scanf("%i", &low);
        printf("High: ");
        scanf("%i", &high);
    } while (high < low);

    int count = 0;
    int valuetofind;
    printf("Find: ");
    scanf("%i", &valuetofind);
    if (valuetofind >= low && valuetofind <= high)
    {
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (mid == valuetofind || low == valuetofind || high == valuetofind)
            {
                count++;
                break;
            }
            else if (mid > valuetofind)
            {
                high = mid - 1;
                count++;
            }
            else
            {
                low = mid + 1;
                count++;
            }
        }
    }
    else
    {
        printf("Not Found.");
        return 1;
    }
    if (low > high)
        printf("Not Found. \nSteps: %i", count);
    else if (valuetofind == mid)
        printf("Found %i\nSteps: %i", mid, count);
    else if (valuetofind == high)
        printf("Found %i\nSteps: %i", high, count);
    else
        printf("Found %i\nSteps: %i", low, count);
}