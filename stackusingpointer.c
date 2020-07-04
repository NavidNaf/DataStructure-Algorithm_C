#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    int top;
    int ara[MAX];
} stack;

void push(stack *s, int value);
void pop(stack *s);

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
        push(&collection, pu);
    }
    else if (strcmp(s, popping) == 0)
    {
        pop(&collection);
    }
    else
    {
        printf("Did Not Enter Push or Pop");
    }
}

void push(stack *s, int value)
{
    if (s->top < MAX)
    {
        s->top = s->top + 1;
        s->ara[s->top] = value;
        printf("Pushed Value: %i\n", value);
        for (int i = 0; i < s->top + 1; i++)
        {
            printf("%i ", s->ara[i]);
        }
    }
    else
    {
        printf("Stack Full.");
    }
}

void pop(stack *s)
{
    if (s->top >= 0)
    {
        int po = s->ara[s->top];
        s->ara[s->top] = 0;
        s->top = s->top - 1;
        printf("Popped Value: %i\n", po);
        for (int i = 0; i < s->top + 1; i++)
        {
            printf("%i ", s->ara[i]);
        }
    }
    else
    {
        printf("Stack Empty.");
    }
}