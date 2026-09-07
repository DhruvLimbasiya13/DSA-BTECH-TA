#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *create_node(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert_node(int value, struct node *root)
{
    if(root == NULL)
    {
        return create_node(value);
    }
    int choice;
    printf("Insert %d to the left or right of %d? (1 for left, 2 for right): ", value, root->value);
    scanf("%d", &choice);
    if (choice == 1)
    {
        root->left = insert_node(value, root->left);
    }
    else if (choice == 2)
    {
        root->right = insert_node(value, root->right);
    }
    else
    {
        printf("Invalid choice. Please try again.\n");
        root = insert_node(value, root);
    }
    return root;
}



int isMirror(struct node *t1, struct node *t2)
{
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 == NULL || t2 == NULL)
        return 0;
    if (t1->value != t2->value)
        return 0;
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

int Check_for_Symmetric(struct node *root1)
{
    if (root1 == NULL)
        return 1;
    return isMirror(root1->left, root1->right);
}

void main()
{
    struct node *root1 = NULL;
    int choice, value;
    while (1)
    {
        printf("\n---- Binary Search Tree Menu ----\n");
        printf("1. Insert Node\n");
        printf("2. Check for Symmetric\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root1 = insert_node(value, root1);
            break;
        case 2:
            {
                int flag = Check_for_Symmetric(root1);
                if (flag)
                {
                    printf("\nTree is Symmetric.\n");
                }
                else
                {
                    printf("\nTree is NOT Symmetric.\n");
                }
            }
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
