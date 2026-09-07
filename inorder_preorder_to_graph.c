#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


//preindex = i
//position = j
struct Node *insert(int inorder[], int preorder[], int start, int end, int *preIndex)
{
    if (start > end)
        return NULL;

    // First element in preorder is root
    int rootValue = preorder[*preIndex];
    (*preIndex)++;

    struct Node *root = createNode(rootValue);

    // Find root in inorder
    int position = search(inorder, start, end, rootValue);

    // Left side of inorder = left subtree
    root->left = insert(inorder, preorder,start, position - 1, preIndex);

    // Right side of inorder = right subtree
    root->right = insert(inorder, preorder,position + 1, end, preIndex);

    return root;
}