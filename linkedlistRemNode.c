#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

//instructions -
//1. if the removing node is first one. change the head.
//2. if except first node -
//2.1. Find the previous node by looping to find if the current node is pointing to the node
//2.2. Check the validity of the the prev node. if it is null or not
//2.3. if found, change the prev node pointer to the one the node points to. 


node *removeNode(node *head, node *node)
{
    //if the first node is to remove
    if (node == head)
    {
        head = node->next;
        free(node);
        return;
    }

    //if any of the rest nodes are removed

    //find the prev node
    node *current = head;
    while (current != NULL)
    {
        if (current->next == node) //if the next pointer of the current node points to the node
        {
            break;
        }
        current = current->next;
    }

    //if the found prev node is valid
    if (current == NULL)
    {
        return head;
    }

    //removal of node
    current->next = node->next; //change the current next pointer to the one node points to
    free(node);
    return head;
}