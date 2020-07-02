// O(n^2)

#include <stdio.h>

int main(void)
{
    int i, j, n;
    scanf("%i", &n);
    int count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            count = count + 1;
        }
    }
    printf("%i - %i", n, count);
}