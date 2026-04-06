// Problem: BST Insert

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

struct node* create(int val){
    struct node* new = malloc(sizeof(struct node));
    new->data = val;
    new->left = new->right = NULL;
    return new;
}

struct node* insert(struct node* root,int val){
    if(root==NULL){
        return create(val);
    }
    if(val<root->data){
        root->left = insert(root->left,val);
    }
    else if(val>root->data){
        root->right = insert(root->right,val);
    }

    return root;
}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
}

int main(){

    int ch;
    int x;
    struct node* root=NULL;
   while(1) {
    printf("Enter choice\n1. Insert\n2. Display\n");
    scanf("%d",&ch);

    if(ch==1){
        printf("Enter element to insert in BST: \n");
        scanf("%d",&x);
        root = insert(root, x);

         }
    else if(ch==2){
        inorder(root);
    }
    else{
        printf("Invalid choice");
    }
    }

}