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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++) //each time the last one is put out
        {
            if (ara[j] > ara[j + 1])
            {
                temp = ara[j];
                ara[j] = ara[j + 1];
                ara[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%i ", ara[i]);
    }
}