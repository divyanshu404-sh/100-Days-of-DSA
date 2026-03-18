// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int dequeue() {
    if (front == NULL)
        return -1;
    struct node* temp = front;
    int val = temp->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
    return val;
}

void reverseQueue(int n) {
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    // Dequeue all elements and push to stack
    while (front != NULL) {
        stack[++top] = dequeue();
    }

    // Pop from stack and enqueue back
    while (top >= 0) {
        enqueue(stack[top--]);
    }

    free(stack);
}

void printQueue() {
    struct node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    reverseQueue(n);
    printQueue();

    return 0;
}