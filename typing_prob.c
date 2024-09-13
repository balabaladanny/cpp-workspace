#include <stdio.h>

typedef struct node {
    char character;
    struct node *ptr_to_next_node;
    struct node *ptr_to_prev_node;
} Node;

Node *head, *tail, *cursor;

Node *create(char x) {
    Node *s = (Node *)malloc(sizeof(Node));
    s->character = x;
    s->ptr_to_next_node = NULL;
    s->ptr_to_prev_node = NULL;
    return s;
}

void insert(Node **cur, char c) {
    Node *temp = create(c);
    temp->ptr_to_next_node = (*cur)->ptr_to_next_node;
    temp->ptr_to_prev_node = *cur;
    (*cur)->ptr_to_next_node = temp;
    (*cur)->ptr_to_next_node->ptr_to_next_node->ptr_to_prev_node = temp;
}

void deletion(Node **cur) {
    Node *temp = (*cur)->ptr_to_next_node;
    if (temp != tail) {
        (*cur)->ptr_to_next_node = (*cur)->ptr_to_next_node->ptr_to_next_node;
        (*cur)->ptr_to_next_node->ptr_to_prev_node = *cur;
        free(temp);
    }
}

void backspace(Node **cur) {
    Node *temp = *cur;
    *cur = (*cur)->ptr_to_prev_node;
    if(temp != head){
        (*cur)->ptr_to_next_node = (*cur)->ptr_to_next_node->ptr_to_next_node;
        (*cur)->ptr_to_next_node->ptr_to_prev_node = (*cur);
        free(temp);
    } else
        *cur = (*cur)->ptr_to_next_node;
}

void go_left(Node **cur, int t) {
    while(t--){
        *cur = (*cur)->ptr_to_prev_node;
    }
}

void go_right(Node **cur, int t) {
    while(t--){
        *cur = (*cur)->ptr_to_next_node;
    }
}

void go_home(Node **cur) {
    *cur = head;
}

void go_end(Node **cur) {
    *cur = tail->ptr_to_prev_node;
}
