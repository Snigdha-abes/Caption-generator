#include <stdio.h>
struct Node {
    int info;
    struct Node* left;
    struct Node* right;
};

int insert();
int search();

int  insert(struct Node *root, int num){
    if (root ==NULL){
        root->left=root->right=NULL;
        root->info=num;
    }
else if(num<root->info)
root->left=insert(root->left,num);
else 
root->right=insert(root->right,num );
}

int search(struct Node *root, int num){
    if (root==NULL)
    printf("Tree is empty ");
    else if (num==root->info)
    printf("Number = %d",num);
    else if (num<root->info)
    search(root->left,num);
    else 
    search(root->right ,num);
}

int BST_min(struct Node*t){
    while(t->left!=NULL){
        t=t->left;
    }
    return t;
}

 int BST_max(struct Node*t){
    while(t->right!=NULL){
        t=t->right;
    }
    return t;
}

int main() {
    struct Node* root = NULL;

    // Insert values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the in-order traversal of the BST
    printf("In-order traversal of the BST: ");
    
    printf("\n");

    // Search for a value in the BST
    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("%d found in the BST.\n", key);
    } else {
        printf("%d not found in the BST.\n", key);
    }

    // Find the minimum value in the BST
    struct Node* minNode = BST_min(root);
    printf("Minimum value in the BST: %d\n", minNode->info);

    // Find the maximum value in the BST
    struct Node* maxNode = BST_max(root);
    printf("Maximum value in the BST: %d\n", maxNode->info);

    return 0;
}
