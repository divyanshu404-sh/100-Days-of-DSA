// Problem: Level Order Traversal

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue {
    struct Node** arr;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int cap) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(sizeof(struct Node*) * cap);
    q->front = q->rear = q->size = 0;
    q->capacity = cap;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->size == q->capacity) return;
    q->arr[q->rear] = node;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

struct Node* dequeue(struct Queue* q) {
    if (q->size == 0) return NULL;
    struct Node* node = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void levelOrder(struct Node* root) {
    if (!root) return;

    struct Queue* q = createQueue(1000);
    enqueue(q, root);

    while (q->size > 0) {
        struct Node* curr = dequeue(q);
        if (!curr) continue;

        printf("%d ", curr->data);

        if (curr->left) enqueue(q, curr->left);
        if (curr->right) enqueue(q, curr->right);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n == 0) return 0;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue(q);
        if (!curr) continue;

        curr->left = newNode(arr[i++]);
        if (curr->left) enqueue(q, curr->left);

        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) enqueue(q, curr->right);
        }
    }

    levelOrder(root);

    return 0;
}