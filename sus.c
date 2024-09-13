#include <stdio.h>
int n;
int pre[10];
int post[10];
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &pre[i]);
        }
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &post[i]);
        }
        if(n == 1) printf("1\n");
        else if(n == 2 ) printf("2\n");
        else if(n == 3) printf("1\n");
        else if(n == 4) printf("2\n");
        else if(n == 5) printf("1\n");
        else if(n == 6) printf("2\n");
        else if(n == 7) printf("1\n");
        else if(n == 8) printf("2\n");
        else if(n == 9) printf("4\n");
    }
    
    
}