#include <stdio.h>

int main(void)
{
    int n;
    printf("Size: ");
    scanf("%i", &n);
    int ara[n];
    int temp;
    for (int i = 0; i < n; i++)
    {
        printf("Value %i: ", i + 1);
        scanf("%i", &ara[i]);
    }
    int index;
    for (int i = 0; i < n - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ara[j] < ara[index])
                index = j; //change index to j if it is greater than the current i
        }

        if (index != i)
        {
            temp = ara[i];
            ara[i] = ara[index];
            ara[index] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", ara[i]);
    }
}