#include <stdio.h>
#include <stdlib.h>

typedef struct TNode
{
    int data;
    struct TNode *left, *right;
} TNode;

TNode *createNode(int data)
{
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TNode *insertOne(TNode *node, int data)
{
    if (node == NULL)
    {
        return createNode(data);
    }

    if (data > node->data)
    {
        node->right = insertOne(node->right, data);
    }
    else if (data < node->data)
    {
        node->left = insertOne(node->left, data);
    }
    return node;
}

void inOrder(TNode *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
    else
    {
        return;
    }
}

void preOrder(TNode *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
    else
    {
        return;
    }
}

int main()
{
    int data[] = {12, 21, 63, 99, 87, 52, 1, 6, 2};
    int i = 0;
    TNode *root = NULL;
    root = insertOne(root, 5);
    insertOne(root, 3);
    insertOne(root, 8);
    insertOne(root, 2);
    insertOne(root, 4);
    insertOne(root, 7);
    insertOne(root, 9);

    for (i = 0; i < 9; i++)
    {
        insertOne(root, data[i]);
    }

    inOrder(root);
    printf("\n");
    preOrder(root);
    return 0;
}
