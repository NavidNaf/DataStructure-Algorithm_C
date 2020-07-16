#include <stdio.h>
#include <stdlib.h>

int count = 0;
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
    node *eight = createNode(8);

    //level 1
    node *three = createNode(3);
    node *ten = createNode(10);

    addleftChild(eight, three);
    addrightChild(eight, ten);

    //level 2
    node *one = createNode(1);
    node *six = createNode(6);
    node *fourteen = createNode(14);

    addleftChild(three, one);
    addrightChild(three, six);
    addrightChild(ten, fourteen);

    //level 3
    node *four = createNode(4);
    node *seven = createNode(7);
    node *thirteen = createNode(13);

    addleftChild(six, four);
    addrightChild(six, seven);
    addleftChild(fourteen, thirteen);

    return eight;
}

void preTraverse(node *root)
{
    printf("%i ", root->data);
    if (root->left != NULL)
    {
        preTraverse(root->left);
    }
    if (root->right != NULL)
    {
        preTraverse(root->right);
    }
}

int searchBST(node *root, int toSearch)
{

    if (root == NULL || root->data == toSearch)
    {
        count++;
        return count;
    }
    if (root->data < toSearch)
    {
        count++;
        searchBST(root->right, toSearch);
        return count;
    }
    else
    {
        count++;
        searchBST(root->left, toSearch);
        return count;
    }
}

node *insertBST(node *root, node *insNode)
{
    if (root == NULL)
    {
        root = insNode;
        return root;
    }
    node *parent = NULL;
    node *current = root;

    while (current != NULL)
    {
        parent = current;
        if (insNode->data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (insNode->data < parent->data)
    {
        addleftChild(parent, insNode);
    }
    else
    {
        addrightChild(parent, insNode);
    }
    return root;
}

int main(void)
{
    node *root = createTree();
    printf("%i\n", root->data);

    preTraverse(root);
    int total = searchBST(root, 17);
    printf("\n");
    printf("Search Steps: %i", total);

    //insert
    node *newNode = createNode(17);
    root = insertBST(root, newNode);
    printf("\n");
    preTraverse(root);
}