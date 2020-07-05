#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int head;
    int tail;
    int ara[MAX];
} queue;

void enqueue(queue *s, int value);
void dequeue(queue *s, int value);

int main(void)
{
    queue collection;

    memset(&collection.ara, 0, sizeof(collection));

    int n;
    printf("Size: ");
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Value %i: ", i + 1);
        scanf("%i", &collection.ara[i]);
    }

    collection.head = 0;
    collection.tail = n;

    // for (int i = 0; i < 8; i++)
    // {
    //     printf("%i \n", collection.ara[i]);
    // }

    //enqueue, dequeue
    char s[7];
    printf("Enqueue/Dequeue: ");
    scanf("%s", s);
    char enq[] = "Enqueue";
    char deq[] = "Dequeue";

    if (strcmp(s, enq) == 0)
    {
        if (collection.tail < MAX)
        {
            int enqvalue;
            printf("Enqueue Value: ");
            scanf("%i", &enqvalue);
            enqueue(&collection, enqvalue);
        }
        else
        {
            printf("Queue Full.");
        }
    }
    else if (strcmp(s, deq) == 0)
    {
        int deqvalue;
        printf("How Many to Dequeue: ");
        scanf("%i", &deqvalue);
        dequeue(&collection, deqvalue);
    }
    else
    {
        printf("Did not Enter Enqueue/Dequeue.");
    }
}

void enqueue(queue *s, int value)
{

    s->tail = s->tail + 1;
    s->ara[s->tail - 1] = value;
    for (int i = 0; i < s->tail; i++)
    {
        printf("%i ", s->ara[i]);
    }
}

void dequeue(queue *s, int value)
{
    s->head = s->head + value;
    if (s->head < s->tail)
    {
        for (int i = s->head; i < s->tail; i++)
        {
            printf("%i ", s->ara[i]);
        }
    }
    else
    {
        printf("Queue Empty.");
    }
}
