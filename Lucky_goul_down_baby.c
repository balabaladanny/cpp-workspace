#include <stdio.h>
#include <stdlib.h>

int ar[2000005];

int binary_search(int *arr, int x, int l, int r) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] > x) {
            return binary_search(ar, x, l, mid - 1);
        } else
            return binary_search(ar, x, mid + 1, r);
    }
    return -1;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int q;
        scanf("%d", &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &ar[i]);
        }
        int x;
        while (q--) {
            scanf("%d", &x);
            int s = binary_search(ar, x, 1, n);
            if (s == -1)
                printf("Break your bridge!\n");
            else
                printf("%d\n", s);
        }
    }
}