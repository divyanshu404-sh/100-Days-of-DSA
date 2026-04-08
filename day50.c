// Problem: BST Search

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

struct node* create(int x){
    struct node* new = malloc(sizeof(struct node));
new->data = x;
new->left = new->right = NULL;
return new;
}

struct node* insert(struct node* root,int x){
    if(root==NULL){
        return create(x);
    }
    if(x<root->data){
        root->left = insert(root->left,x);
    }
    else if(x>root->data){
        root->right = insert(root->right,x);
    }

    return root;
}

struct node* search(struct node* root,int k){
    if(root==NULL || root->data==k){
        return root;
    }
    if(k<root->data){
        return search(root->left,k);
    }
    else{
        return search(root->right,k);
    }
}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    printf("%d,",root->data);
    inorder(root->right);
}

int main(){

    int ch,x,k;
    struct node* root = NULL;

while(1){
    printf("Enter choice:\n1.Insert\n2.Search\n3.Display\n");
    scanf("%d",&ch);

    if(ch==1){
        printf("Enter element:\n");
        scanf("%d",&x);
        root = insert(root,x);
    }
    else if(ch==2){
        printf("Enter element to search:\n");
        scanf("%d",&k);
        if(search(root,k)==NULL){
            printf("Not found\n");
        }
        else{
        printf("%d found\n",search(root,k)->data);
    }
    }
    else if(ch==3){
        inorder(root);
    }
    else{
        printf("Invalid choice\n");
        exit(0);
    }
}
}