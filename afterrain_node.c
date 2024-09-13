#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct _NODE {
//     char color[10];
//     struct _NODE *next;
// }Node;

void insert(Node **head, char *color, int n) {
    Node *cur = *head;
    while (cur->next && n--) cur = cur->next;
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->color, color);
    newNode->next = cur->next;
    cur->next = newNode;
}

void erase1(Node **head, int n) {
    Node *cur = *head;
    Node *prev = NULL;
    while (cur->next && n--) {
        prev = cur;
        cur = cur->next;
    }
    if (prev != NULL) {
        Node *tmp = cur;
        prev->next = prev->next->next;
        free(tmp);
    }
}

void erase2(Node **head, char *color) {
    Node *cur = *head;
    Node *prev;
    while (cur->next) {
        prev = cur;
        cur = cur->next;
        if (strcmp(color, cur->color) == 0) {
            Node *tmp = cur;
            prev->next = prev->next->next;
            free(tmp);
            cur = prev;
        }
    }
}
// strcmp

// void reverse(Node **head, int dest_1, int dest_2) {
//     Node *temp1 = *head;
//     Node *temp2;
//     Node *temp3 = *head;
//     Node *end;
//     Node *begin;
//     if (dest_1 == dest_2)
//         return;
//     while (temp1->next && dest_1--) {
//         begin = temp1;
//         temp1 = temp1->next;
//     }
//     while (temp3->next && dest_2--) {
//         temp3 = temp3->next;
//     }
//     if (temp1 == temp3)
//         return;
//     temp3 = temp3->next;
//     end = temp3;
//     temp2 = temp1->next;
//     while(temp2 != end) {
//         temp1->next = temp3;
//         temp3 = temp1;
//         temp1 = temp2;
//         temp2 = temp1->next;
//     }
//     temp1->next = temp3;
//     begin->next = temp1;
// }

void reverse(Node **head, int dest1, int dest2)
{
	Node *now = (*head), *l = NULL, *tmp = NULL;
	int id;
	for(id = 0; now->next!=NULL && id!=dest1; l = now, now = now->next, id++);
	while(now->next!=NULL&&id<dest2)
	{
		tmp = now->next;
		now->next = tmp->next;
		tmp->next = l->next;
		l->next = tmp;
		id++;
	}
}