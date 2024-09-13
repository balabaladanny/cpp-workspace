#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
    char c;
    int num;
    int sym; // 0 is number, 1 is sign, 2 unknown;
    struct NODE *left;
    struct NODE *right;
} Node;

char str[105];
int pos;
Node *root;
int x, y, z;

Node* buildTree() {
    Node *root = (Node*)malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;
    if (str[pos] == '+' || str[pos] == '-' || str[pos] == '*' || str[pos] == '/') {
        root->sym = 1;
        root->c = str[pos];
        pos += 2;
        root->left = buildTree();
        root->right = buildTree();
    } else {
        if (str[pos] == 'x' || str[pos] == 'y' || str[pos] == 'z') {
            root->sym = 2;
            root->c = str[pos];
            pos += 2;
        } else {
            int num = 0;
            while (str[pos] != ' ' && pos != strlen(str)) {
                num *= 10;
                num += str[pos] - '0';
                pos++;
            }
            root->sym = 0;
            root->num = num;
            pos++;
        }
    }
    return root;
}

int evaluate(Node *root) {
    int lv, rv;
    if (root->left)
        lv = evaluate(root->left);
    if (root->sym == 0) {
        printf("%d", root->num);
        return root->num;
    }
    else {
        printf("%c", root->c);
        if (root->sym == 2) {
            if (root->c == 'x')
                return x;
            else if (root->c == 'y')
                return y;
            else if (root->c == 'z')
                return z;
        }
    }
    if (root->right)
        rv = evaluate(root->right);
    if (root->c == '+')
        return lv + rv;
    else if (root->c == '-')
        return lv - rv;
    else if (root->c == '*')
        return lv * rv;
    else if (root->c == '/')
        return lv / rv;
}

int main() {
    gets(str);
    scanf("%d %d %d", &x, &y, &z);
    pos = 0;
    root = buildTree();
    printf("\n%d\n", evaluate(root));
} 