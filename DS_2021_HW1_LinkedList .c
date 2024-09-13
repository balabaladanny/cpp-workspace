#include <stdio.h>
#include <stdlib.h>
int N, M, K;  //N個人 M張牌 K個人有鬼牌

typedef struct node {
    int index;
    struct node *next;
} Node;

Node **head_po;

Node *create(int n) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->index = n;
    node->next = NULL;
    return node;
}

void replace(int i) {
    head_po[i]->next->index = 0;
}

void give(int a, int b, int n) {
    Node *cur_1 = head_po[n];
    Node *cur_2;
    Node *temp;
    if (n + 1 > N)
        temp = head_po[1];
    else
        temp = head_po[n + 1];
    for (int i = 0; cur_1->next && i < (b - 1); i++) {
        cur_1 = cur_1->next;
    }
    for (int i = 0; temp->next->next && i < (a - 1); i++) {
        temp = temp->next;
    }
    cur_2 = temp->next;
    temp->next = temp->next->next;
    cur_2->next = cur_1->next;
    cur_1->next = cur_2;
}

int main(void) {
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &K);
    //建dummy head
    head_po = (Node **)malloc(sizeof(Node *) * (N + 1));
    for (int i = 1; i <= N; i++)
        head_po[i] = create(-1);
    //建每人的牌
    for (int k = 1; k <= N; k++) {
        Node *cur = head_po[k];
        for (int i = 1; i <= M; i++) {
            Node *newnode = create(i);
            cur->next = newnode;
            cur = cur->next;
        }
    }
    //處理一開始有joker
    while (K--) {
        int z;
        scanf("%d", &z);
        replace(z);
    }
    int a, b;
    int n = 1;
    while (scanf("%d%d", &a, &b) != EOF) {
        if (a == -1 && b == -1) {
            int flag = 1;  //判斷有沒有joker
            Node *curr;    //拿來檢查的
            Node *currr;   //拿來印的
            for (int i = 1; i <= N; i++) {
                curr = head_po[i]->next;
                currr = head_po[i]->next;
                while (curr) {
                    if (curr->index == 0) {
                        flag = 0;
                        break;
                    } else {
                        curr = curr->next;
                    }
                }
                if (!curr) {
                    if (currr) {
                        printf("%d", currr->index);
                        currr = currr->next;
                    }
                    while (currr) {
                        printf(" %d", currr->index);
                        currr = currr->next;
                    }
                    printf("\n");
                    break;
                }
            }
            break;
        } else {
            if (n > N) {
                n = 1;
            }
            give(a, b, n);
            n++;
        }
    }

    // for(int i = 1 ; i <= N  ; i++){
    //     Node *tmp = head_po[i];
    //     while(tmp){
    //         Node *node;
    //         node = tmp;
    //         tmp = tmp->next;
    //         free(node);

    //     }
    // }
}
