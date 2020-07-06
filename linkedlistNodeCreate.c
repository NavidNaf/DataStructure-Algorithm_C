//create a node
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createnode(int data, node *next)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Error");
        exit(1);
    }
    newNode->data = data;
    newNode->next = next;
}

int main(void)
{
    node *n;
    n = createnode(10, NULL);
    printf("%i", n->data);
}