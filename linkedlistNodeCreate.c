//create a node
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createnode(int data, node *next) // returns pointer to the node
{
    //memory allocation
    node *newNode = (node *)malloc(sizeof(node));

    //checking if the newNode has allocated memory or not
    if (newNode == NULL)
    {
        printf("Error");
        exit(1);
    }

    //assigning values to the structure
    newNode->data = data;
    newNode->next = next;
}

//1. Create a node and allocate memory
//2. Check if the memory has been allocated or not
//3. Assign values to the structure 

int main(void)
{
    node *n;
    n = createnode(10, NULL);
    printf("%i", n->data);
}