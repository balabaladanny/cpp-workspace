#include <stdio.h>

long long int* num_arr;
unsigned long long int* presum_arr;
long long int a, b;
long long int real_a = 0, real_b = 0;
unsigned long long sum = 0;
unsigned long long temp_sum = 0;

int main() {
    long long int n, q;
    while (scanf("%lld%lld", &n, &q) != EOF) {
        num_arr = (long long int*)malloc(sizeof(long long int)*n);
        presum_arr = (unsigned long long*)malloc(sizeof(unsigned long long)*n);
        for (long long int i = 1; i <= n; i++) {
            scanf("%lld", &num_arr[i]);
        }

        presum_arr[0] = 0;
        presum_arr[1] = num_arr[1];
        for (long long int i = 2; i <= n; i++) {
            presum_arr[i] = presum_arr[i - 1] + num_arr[i];
        }

        real_a = 0;
        real_b = 0;
        sum = 0;
        temp_sum = 0;
        while (q--) {
            scanf("%lld%lld", &a, &b);
            if (a > b) {
                temp_sum = presum_arr[n] - presum_arr[a - 1] + presum_arr[b];
            } else {
                temp_sum = presum_arr[b] - presum_arr[a - 1];
            }

            if (temp_sum > sum) {
                sum = temp_sum;
                real_a = a;
                real_b = b;
            }
        }
        printf("Max_range: (%lld,%lld)", real_a, real_b);
        printf("; Value: %llu\n", sum);
        free(num_arr);
        free(presum_arr);
    }
}