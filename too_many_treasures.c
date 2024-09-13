#include <stdio.h>

int main() {
    int n, q,neg_idx;
    scanf("%d %d", &n, &q);

    long long treasures[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &treasures[i]);
        if(treasures[i] < 0){
            neg_idx = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if(treasures[i] < 0){
            neg_idx = i;
            break;
        }
    }
    unsigned long long prefixSum[n + 1];
    prefixSum[0] = 0;
    for (int j = 1; j <= n; j++) {
        prefixSum[j] = prefixSum[j - 1] + treasures[j];
    }
    
    for (int i = 0; i < q; i++) {
        int l, r, m;
        scanf("%d %d %d", &l, &r, &m);

        // long long maxSum = 0;

        unsigned long long val = 0;
        int new_r;
        
        if(r-l+1 > m) {
            new_r = l+m-1;
        }
        else {
            new_r = r;
        }
        if(new_r >= neg_idx) {
            
            new_r = neg_idx - 1;
        }
        
        if(new_r >= l) {
            val = prefixSum[new_r] - prefixSum[l-1];
        }
        else {
            val = 0;
        }
        

        printf("%llu\n", val);
        
    }

    return 0;
}
