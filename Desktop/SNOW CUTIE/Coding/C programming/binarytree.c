#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void printInorder();
void printPostorder();
void printPreorder();
int create();
// TRAVERSAL.....
// INORDER.....
void printInorder(struct node *p)
{
    if (p != NULL)
    {
        printInorder(p->left);
        printf("%d ", p->data);
        printInorder(p->right);
    }
}
// PREORDER.....
void printPreorder(struct node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        printPreorder(p->left);
        printPreorder(p->right);
    }
}
// POSTORDER.....
void printPostorder(struct node *p)
{
    if (p != NULL)
    {
        printPostorder(p->left);
        printPostorder(p->right);
        printf("%d ", p->data);
    }
}
int create()
{
    int x;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    printf("Enter data (-1 for no data) : ");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    else
        p->data = x;
    printf("Enter the left child of %d ", x);
    p->left = create();
    printf("Enter the right child of %d ", x);
    p->right = create();
    return p;
}
int main()
{
    struct node *root;
    root = create();
    printf("Preorder : ");
    printPreorder(root);
    printf("\n");
    printf("Postorder : ");
    printPostorder(root);
    printf("\n");
    printf("Inorder : ");
    printInorder(root);
}