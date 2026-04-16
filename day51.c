// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 6 2 8 0 4 7 9
// 2 8

// Output:
// 6

#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* left;
    struct node* right;
};

struct node* create(int x){
    struct node* new = malloc(sizeof(struct node));
    new->val = x;
    new->left = new->right = NULL;
    return new;
}

struct node* insert(struct node* root,int x){
    if(root==NULL){
        return create(x);
    }
    if(x<root->val){
        root->left = insert(root->left,x);
    }
    else if(x>root->val){
        root->right = insert(root->right,x);
    }
    return root;
}

struct node* lca(struct node* root,int p,int q){
    if (root == NULL) return NULL;

    if (root->val == p || root->val == q)
        return root;

    if (p < root->val && q < root->val)
        return lca(root->left, p, q);

    if (p > root->val && q > root->val)
        return lca(root->right, p, q);

    return root;
}


int main(){

    struct node* root = NULL;

    while(1){
    int ch;
    printf("Enter choice:\n1.insert\n2.find lowest common ancestor\n");
    scanf("%d",&ch);

    if(ch==1){
        int x;
        printf("Enter number to insert:\n");
        scanf("%d",&x);
        root = insert(root,x);
    }
    else if(ch==2){
        int p,q;
        printf("Enter numbers:\n");
        scanf("%d %d",&p,&q);
        printf("Lowest common ancestor=%d\n",lca(root,p,q)->val);
    }

}
}