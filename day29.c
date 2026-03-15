// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){

    int n;
    printf("Enter no. of elemnets:\n");
    scanf("%d",&n);
    
    struct node* head = NULL;
    struct node* new = NULL;
    struct node* temp = NULL;
    struct node* tail = NULL;
    int x;
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        new = (struct node*)malloc(sizeof(struct node));
        new->data = x;
        new->next = NULL;
        if(head==NULL){
            head = new;
            temp = head;
        }
        else{
            temp->next = new;
            temp = new;
        }
    }
    temp->next=head;

    int k;
    printf("Enter k:\n");
    scanf("%d",&k);
    temp=head;
    for(int i=0;i<k;i++){
        temp=temp->next;
    }
    head = temp->next;
    tail = temp;
    temp=head;
    for(int i=0;i<n;i++){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}