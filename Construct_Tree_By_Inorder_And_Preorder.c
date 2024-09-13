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
    
}
int pre_num = 0;
Node* buildTree(int* Inorder, int* Preorder, int inorder_start, int inorder_end)
{
    if(inorder_start > inorder_end)return NULL;
    Node *now = (Node*)malloc(sizeof(Node));
    now->number = Preorder[pre_num];
    pre_num++;
    int inorder_mid = find(Inorder, inorder_start, inorder_end, now->number);
    now -> ptr_to_left_node = buildTree(Inorder, Preorder, inorder_start, inorder_mid-1);
    now -> ptr_to_right_node = buildTree(Inorder, Preorder, inorder_mid+1, inorder_end);
    return now;
}
void showPostorder(Node* root)
{
    if(root == NULL)return;
    showPostorder(root->ptr_to_left_node);
    showPostorder(root->ptr_to_right_node);
    printf("%d ", root->number);
}

void freeTree(Node *root)
{
    pre_num = 0;
    if(root == NULL)return;
    freeTree(root->ptr_to_left_node);
    freeTree(root->ptr_to_right_node);
    free(root);
}





int main(void)
{
    int id = 1;
    while( ~scanf( "%d", &n ) )
    {
        int inorder[100], preorder[100];
        for( int i = 0; i < n; i++ )
            scanf( "%d", &inorder[i] );
        for( int i = 0; i < n; i++ )
            scanf( "%d", &preorder[i] );
        Node *root = buildTree( inorder, preorder, 0, n-1 );
        printf( "testcase%d: ", id++ );
        showPostorder( root );
        printf( "\n" );
        freeTree( root );
    }
    return 0;
}
