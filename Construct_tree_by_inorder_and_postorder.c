#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;

int n;

int find(int* in_arr, int begin,int end, int target){
    for(int i = begin ; i <= end ; i++){
        if(in_arr[i] == target){
            return i;
        }
    }
    return end;
}

Node* buildTree(int* Inorder, int* Postorder, int inorder_start, int inorder_end)
{
    if(inorder_start > inorder_end)return NULL;
    Node *now = (Node*)malloc(sizeof(Node));
    now->number = Postorder[n-1];
    n--;
    int inorder_mid = find(Inorder, inorder_start, inorder_end, now->number);
    now -> ptr_to_right_node = buildTree(Inorder, Postorder, inorder_mid+1, inorder_end);
    now -> ptr_to_left_node = buildTree(Inorder, Postorder, inorder_start, inorder_mid-1);
    return now;
}
void showPreorder(Node* root)
{
    if(root == NULL)return;
    printf("%d ", root->number);
    showPreorder(root->ptr_to_left_node);
    showPreorder(root->ptr_to_right_node);
}

void freeTree(Node *root)
{
    n = 0;
    if(root == NULL)return;
    freeTree(root->ptr_to_left_node);
    freeTree(root->ptr_to_right_node);
    free(root);
}





int main(void)
{
    int id = 1;
    while( ~scanf( "%d", &n ))
    {
        int inorder[100], postorder[100];
        for( int i = 0; i < n; i++ )
            scanf( "%d", &inorder[i] );
        for( int i = 0; i < n; i++ )
            scanf( "%d", &postorder[i] );
        Node *root = buildTree( inorder, postorder, 0, n-1 );
        printf( "testcase%d: ", id++ );
        showPreorder( root );
        printf( "\n" );
        freeTree( root );
    }
    return 0;
}
