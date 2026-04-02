// Problem: Count Leaf Nodes

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int countleaf(struct node* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return countleaf(root->left) + countleaf(root->right);
}

int main(){
    struct node* root = malloc(sizeof(struct node));
    struct node* left1 = malloc(sizeof(struct node));
    struct node* right1 = malloc(sizeof(struct node));
    struct node* right11 = malloc(sizeof(struct node));
    root->data = 1;
    root->left = left1;
    root->right = right1;

    left1->data = 2;
    left1->left = left1->right = NULL;

    right1->data = 3;
    right1->left =  NULL;
    right1->right = right11;
    right11->data = 5;
    right11->left = right11->right = NULL;

    printf("Number of leaf nodes = %d\n", countleaf(root));

    free(left1);
    free(right1);
    free(root);
    free(right11);

    return 0;
}