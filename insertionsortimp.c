//see programming_prac_p3
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

    for (int i = 1; i < n; i++)
    {
        temp = ara[i];
        int j = i - 1;
        while (j >= 0 && ara[j] > temp)
        {
            ara[j + 1] = ara[j];
            j--;
        }
        ara[j + 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%i ", ara[i]);
    }
}