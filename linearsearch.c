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
    int valuetofind;
    printf("Find: ");
    scanf("%i", &valuetofind);

    int z = -1;
    for (int i = 0; i < n; i++)
    {
        if (ara[i] == valuetofind)
        {
            printf("Value %i found at Position %i", ara[i], i + 1);
            z = 0;
            break;
        }
    }
    if (z == -1)
        printf("Not Found.");
}