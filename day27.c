// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* create(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

int length(struct Node* head) {
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* intersection(struct Node* l1, struct Node* l2) {
    int len1 = length(l1);
    int len2 = length(l2);

    while(len1 > len2) {
        l1 = l1->next;
        len1--;
    }
    while(len2 > len1) {
        l2 = l2->next;
        len2--;
    }

    while(l1 && l2) {
        if(l1->data == l2->data) return l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    return NULL;
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* l1 = create(n);

    scanf("%d", &m);
    struct Node* l2 = create(m);

    struct Node* inter = intersection(l1, l2);

    if(inter) printf("%d", inter->data);
    else printf("No Intersection");

    return 0;
}