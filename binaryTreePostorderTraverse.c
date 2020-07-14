#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int item)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Error!");
        exit(1);
    }
    new->data = item;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void addleftChild(node *parent, node *child)
{
    parent->left = child;
}

void addrightChild(node *parent, node *child)
{
    parent->right = child;
}

node *createTree()
{
    //root
    node *two = createNode(2);

    //level1
    node *seven = createNode(7);
    node *nine = createNode(9);

    addleftChild(two, seven);
    addrightChild(two, nine);

    //level 2
    node *one = createNode(1);
    node *six = createNode(6);
    node *eight = createNode(8);

    addleftChild(seven, one);
    addrightChild(seven, six);
    addrightChild(nine, eight);

    //level 3
    node *five = createNode(5);
    node *ten = createNode(10);
    node *three = createNode(3);
    node *four = createNode(4);

    addleftChild(six, five);
    addleftChild(eight, three);
    addrightChild(six, ten);
    addrightChild(eight, four);

    return two;
}

void postTraverse(node *root)
{
    if (root->left != NULL)
    {
        postTraverse(root->left);
    }
    if (root->right != NULL)
    {
        postTraverse(root->right);
    }
    printf("%i ", root->data);
}

int main(void)
{
    node *root = createTree();
    printf("Root Node: %i\n", root->data);

    postTraverse(root);
}