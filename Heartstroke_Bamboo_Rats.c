#include <stdlib.h>
#include <stdio.h>

typedef struct _NODE {
    int level;
    struct _NODE *left_child, *right_child;
} Node;

#define L left_child
#define R right_child


Node *new_Node(int x){
    Node *node = (Node*)malloc(sizeof(Node));
    node->L = node->R = NULL;
    node->level = x;
    return node;
}

void build_tree(Node **now, int *arr, int l, int r)
{
    if(l>r) return;
    int mid = (l+r)/2;
    (*now) = new_Node(arr[mid]);
    build_tree(&((*now)->L), arr, l, mid-1);
    build_tree(&((*now)->R), arr, mid+1, r);
}
int query_heatstroke(Node *now, int x)
{
    if(now==NULL) return 0;
    if(now->level > x) return query_heatstroke(now->L, x);
    else if(now->level < x) return query_heatstroke(now->R, x);
    else return 1;
}
void eat_rat(Node **root, int x)
{
    while((*root)!=NULL && (*root)->level!=x)
    {
        if((*root)->level > x) root = &((*root)->L);
        if((*root)->level < x) root = &((*root)->R);
    }
    if((*root) == NULL) return;
    if(!(*root)->L && !(*root)->R)
    {
        free(*root);
        (*root) = NULL;
    }
    else if((*root)->L && (*root)->R)
    {
        Node **l = &((*root)->L);
        while((*l)->R) l = &((*l)->R);
        (*root)->level = (*l)->level;
        eat_rat(l, (*l)->level);
    }
    else
    {
        Node *now = (*root)->L ? (*root)->L : (*root)->R;
        free(*root);
        (*root) = now;
    }
}