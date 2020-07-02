#include <stdio.h>

int main(void)
{
    int i, j, n, even[101];
    for (i = 0; i < 101; i++)
    {
        even[i] = 0;
    }
    for (j = 0; j < 101; j = j + 2)
    {
        even[j] = 1;
    }

    printf("Enter Number: ");
    scanf("%i", &n);

    if (even[n])
        printf("Even.\n");
    else
        printf("Odd.\n");
}