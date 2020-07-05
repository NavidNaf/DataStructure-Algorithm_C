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
            collection.tail = collection.tail + 1;
            int enqvalue;
            printf("Enqueue Value: ");
            scanf("%i", &enqvalue);
            collection.ara[collection.tail - 1] = enqvalue;
            for (int i = 0; i < collection.tail; i++)
            {
                printf("%i ", collection.ara[i]);
            }
            //printf("%i ", collection.tail);
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
        collection.head = collection.head + deqvalue;
        //printf("%i", collection.head);
        if (collection.head < collection.tail)
        {

            for (int i = collection.head; i < collection.tail; i++)
            {
                printf("%i\n", collection.ara[i]);
            }
        }
        else
        {
            printf("Queue Empty.");
        }
    }
    else
    {
        printf("Did not Enter Enqueue/Dequeue.");
    }
}