#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} Node;

int sz;
Node *prev;

Node *create(int num) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->number = num;
    node->next = NULL;
    return node;
}

Node *createList(int n) {
    sz = n;
    Node *cur;
    Node *head = create(1);
    cur = head;
    int a = 2;
    while (a != n + 1) {
        Node *newnode = create(a);
        cur->next = newnode;
        cur = cur->next;
        a++;
        if (a == n + 1)
        prev = cur;
    }
    cur->next = head;
    return head;
}

void freeList(Node *head) {
    free(head);
}

int solveJosephus(Node **head, int step) {
    Node *curr = *head;
    Node *temp;
    while (curr->next != curr) {
        for (int i = 0; i < (step - 1) % sz; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = prev->next->next;
        temp = curr;
        curr = curr->next;
        free(temp);
        sz -= 1;
    }
    *head = curr;
    return curr->number;
}