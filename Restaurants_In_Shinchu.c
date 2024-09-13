#include <stdio.h>
#include <stdlib.h>
long long int max = 1000000007;
typedef struct {
    long long int M[2][2];
}matrix;

matrix Mul(matrix a, matrix b){
    matrix ans;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ans.M[i][j] = 0;
            for(int k=0;k<2;k++)
                ans.M[i][j] += (a.M[i][k] * b.M[k][j])%max;
            ans.M[i][j] %= max;
        }
    }
	return ans;
}
matrix create(){
    matrix X;
    X.M[0][0] = 1;
    X.M[0][1] = 1;
    X.M[1][0] = 1;
    X.M[1][1] = 0;
    return X;
}

matrix fb(long long int i){
    if(i==1)
        return create();
    matrix now = fb(i/2);
    if(i%2 == 0)
        return Mul(now, now);
    return Mul(Mul(now, now), fb(1));
}

int main(){
    //initialize
    long long int i;
    while(scanf("%lld", &i) != EOF){
        matrix  fx;
        if(i == 1 || i==2)
            printf("%lld\n", 1);
        else {
            fx = fb(i - 2);
            long long int ans;
            ans = (fx.M[0][0] + fx.M[0][1]) % max;
            printf("%lld\n", ans);
        }
    }

}