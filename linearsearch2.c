#include <stdio.h>

int find(int ara[], int n, int x)
{
    int z = -1;
    for (int i = 0; i < n; i++)
    {
        if (ara[i] == x)
        {
            return i + 1;
        }
    }
    return -1;
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
    int valuetofind;
    printf("Find: ");
    scanf("%i", &valuetofind);
    int result = find(ara, n, valuetofind);

    if (result == -1)
        printf("Not Found.");
    else
        printf("Value %i found at Position %i", valuetofind, result);
}