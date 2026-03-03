// Problem: Count Nodes in Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){

    struct node * head=NULL; 
    struct node * temp=NULL; 
    struct node * new=NULL;

    int n;
    printf("Enter no. of elements:\n");
    scanf("%d",&n);

    int x;
    for(int i=0;i<n;i++){
        new=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&x);
        new->data=x;
        if(head==NULL){
            head=new;
            temp=new;
        }
        else{
            temp->next=new;
            temp=new;
        }
    }
    int count =0;
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
        count++;
    }

    printf("\nNo. of nodes = %d\n",count);

    return 0;
}