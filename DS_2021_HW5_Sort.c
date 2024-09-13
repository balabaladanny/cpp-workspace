#include <stdio.h>

int initial[1000005];
int n,count;
void zxz(int pos_sign,int neg_sign){
    if(pos_sign < n && neg_sign >= 0){
        if((initial[pos_sign] < (-initial[neg_sign]))){
            printf("%d%s",initial[pos_sign],count == (n-1)? "":" ");
            count++;
            pos_sign++;
            zxz(pos_sign,neg_sign);
        }
        else if((initial[pos_sign] > (-initial[neg_sign]))) {
            printf("%d%s",initial[neg_sign],count == (n-1)? "":" ");
            count++;
            neg_sign--;
            zxz(pos_sign,neg_sign);
        }
        else if((initial[pos_sign]) == (-initial[neg_sign])){
            printf("%d%s",initial[neg_sign],count == (n-1)? "" : " ");
            count++;
            neg_sign--;
            zxz(pos_sign,neg_sign);
        }
    }
    
    else if(pos_sign >= n && neg_sign >= 0){
        for(int i = neg_sign ; i >= 0 ; i--){
            printf("%d%s",initial[neg_sign],count == (n-1)? "" : " ");
            count++;
            neg_sign--;
        }
    }
    else if(neg_sign < 0 && pos_sign < n ){
        for(int i = pos_sign ; i < n ; i++){
            printf("%d%s",initial[pos_sign],count == (n-1)? "" : " ");
            count++;
            pos_sign++;
        }
    }
}

int main(void){
    while(scanf("%d",&n)!= EOF){
        count = 0;
        
        int pos_sign = -1;
        
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&initial[i]);
            if(initial[i-1] < 0 && initial[i] >= 0){
                pos_sign = i;
            }
        }
        
        if(pos_sign == -1){
            if(initial[n-1] >= 0){
                for(int i = 0 ; i < n ; i++){
                    printf("%d%s",initial[i],i == (n - 1)? "":" ");
                }
            }
            else {
                for(int i = n - 1 ; i >= 0 ; i--){
                    printf("%d%s",initial[i],i == 0? "":" ");
                }
            }
        }
        else{
            int neg_sign = pos_sign - 1;
            zxz(pos_sign,neg_sign);
    }
        printf("\n");
        
    }
}
