#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode(int item, node *next)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Error!");
        exit(1);
    }
    new->data = item;
    new->next = next;
}

node *removeNode(node *head, node *remnode)
{
    //case 1: removal of first data
    if (remnode == head)
    {
        head = remnode->next;
        free(remnode);
        return head;
    }

    //case 2.1: finding prev node
    node *current = head;
    while (current != NULL)
    {
        if (current->next == remnode)
        {
            break;
        }
        current = current->next;
    }

    //case 2.2: validity check
    if (current == NULL)
    {
        return head;
    }

    //case 2.3: removal if found
    current->next = remnode->next;
    free(remnode);
    return head;
}

node *prepend(node *head, int item)
{
    node *new = createNode(item, head);
    return new;
}

node *append(node *head, int item)
{
    node *new = createNode(item, NULL);
    //checking if list is empty or not
    if (head == NULL)
    {
        return new;
    }

    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new;
    return head;
}

void *insert(node *insnode, int item) //after insnode
{
    node *new = createNode(item, insnode->next);
    insnode->next = new;
}

void printnode(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%i\n", current->data);
        current = current->next;
    }
    printf("\n");
}

void *searchNode(node *head, node *searchThis)
{
    int count = 0;
    node *current = head;
    while (current != searchThis)
    {
        count++;
        current = current->next;
    }
    printf("Total Count: %i", count);
}
int main(void)
{
    //create node
    int n;
    node *createData;
    printf("Data: ");
    scanf("%d", &n);
    createData = createNode(n, NULL);               //second node current
    node *createData2 = createNode(87, createData); //first node current
    printf("%d\n", createData2->data);

    //check head
    node *head = createData2;
    printf("Current H: %d\n", head->data);

    //prepend
    head = prepend(head, 95);
    printf("Current H: %d", head->data);

    //append
    head = append(head, 744);

    //insert
    insert(createData, 78);

    printnode(head);

    searchNode(head, createData);

    //remove
    head = removeNode(head, createData2);
    printf("Current H: %d", head->data);
}