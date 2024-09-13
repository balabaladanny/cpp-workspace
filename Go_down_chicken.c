#include <stdio.h>

int n,q;
typedef struct _Data
{
    int idx;
    int data;
}Data;
Data arr[1000005];
int main(){
    while(scanf("%d%d", &n,&q)){
        for(int i = 0 ; i < n ; i++){
            int tmp;
            scanf("%d(/`A`)/ ~I__I ", &tmp);
            arr[i].idx = i+1;
            if(tmp%2 == 1){
                arr[i].data = 0;
            }
            else arr[i].data = fpw(tmp/2);
        }
    }
}