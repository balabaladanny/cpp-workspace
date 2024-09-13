#include <stdio.h>
#include <string.h>

char a[1005];
char b[1005];
int pre_sum[1005];
int sum[1005];
int main(void) {
    while (scanf("%s", a) != EOF) {
        scanf("%s", b);
        int times;
        scanf("%d", &times);
        int len_a = strlen(a);
        int len_b = strlen(b);
        int sum[1005] = {0};
        int index = 0;
        len_b--;
        while (index < len_b) {
            sum[index] = 0;
            pre_sum[index] = 0;
            index++;
        }
        len_a--;
        while (index <= len_a) {
            for (int i = index, j = len_b; i >= (index - len_b); i--, j--) {
                if (a[i] != b[j])
                    break;
                if (i == (index - len_b))
                    sum[index]++;
            }
            index++;
        }
        for (int i = len_b; i <= len_a; i++) {
            pre_sum[i] = pre_sum[i - 1] + sum[i];
        }
        int ma = 0;
        while (times--) {
            int l, r;
            scanf("%d", &l);
            scanf("%d", &r);
            l--;
            r--;
            l = l + len_b - 1;
            if (r - l <= len_b)
                continue;
            if (ma < pre_sum[r] - pre_sum[l])
                ma = pre_sum[r] - pre_sum[l];
        }
        printf("%d\n", ma);
    }
}