#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    int top;
    int ara[MAX];
} stack;

int main(void)
{
    //assigning stack
    stack collection;

    //assigning array to 0
    memset(&collection.ara, 0, sizeof(collection));

    //assigning top to -1
    collection.top = -1;

    //array from user input
    int n;
    printf("Size of YOUR Array: ");
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Value %i: ", i + 1);
        scanf("%i", &collection.ara[i]);
    }
    collection.top = collection.top + n;

    // printf("%i\n", collection.top);
    // for (int i = 0; i < 8; i++)
    // {
    //     printf("%i ", collection.ara[i]);
    // }

    //push pop
    int pu, po;
    char s[4];
    char pushing[] = "Push";
    char popping[] = "Pop";
    printf("Push/Pop: ");
    scanf("%s", s);
    if (strcmp(s, pushing) == 0)
    {
        printf("Push Value: ");
        scanf("%i", &pu);
        collection.top = collection.top + 1;
        collection.ara[collection.top] = pu;
        printf("Pushed Value: %i\n", pu);
        for (int i = 0; i < collection.top + 1; i++)
        {
            printf("%i ", collection.ara[i]);
        }
    }
    else if (strcmp(s, popping) == 0)
    {
        int po = collection.ara[collection.top];
        collection.ara[collection.top] = 0;
        collection.top = collection.top - 1;
        printf("Popped Value: %i\n", po);
        for (int i = 0; i < collection.top + 1; i++)
        {
            printf("%i ", collection.ara[i]);
        }
    }
    else
    {
        printf("Did Not Enter Push or Pop");
    }
}
