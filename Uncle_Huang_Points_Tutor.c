#include <stdio.h>

int main(void) {
    unsigned long long int a, b;
    scanf("%llu", &a);
    scanf("%llu", &b);
    unsigned long long int n;
    scanf("%llu", &n);
    unsigned long long int ans = 1;
    a = a % n;
    while (b != 0) {
        if (b & 1 == 1) ans = (ans * a) % n;
        b >>= 1;
        a = (a * a) % n;
    }
    if(b == 0 && n == 1) printf("0\n");
    else{
        printf("%llu\n", ans);
    }
}