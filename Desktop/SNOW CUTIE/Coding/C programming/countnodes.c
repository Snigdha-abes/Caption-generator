#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int countNodes(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct node *root = NULL;

    // Get tree structure from user input
    printf("Enter the tree structure in pre-order format (-1 for NULL nodes):\n");
    int data;
    scanf("%d", &data);
    if (data != -1) {
        root = createNode(data);
        root->left = createTree(root->left);
        root->right = createTree(root->right);
    }

    int numNodes = countNodes(root);
    printf("Number of nodes in the binary tree: %d\n", numNodes);

    return 0;
}