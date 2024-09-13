#include <stdio.h>

int first[1000005];
long long int second[1000005] = {0};

int check(int n);

int main() {
    int times;
    scanf("%d", &times);
    for (int i = 1; i <= 1000000; i++) {
        first[i] = check(i);
    }

    second[1] = first[1];
    for (int i = 2; i <= 1000000; i++) {
        second[i] = second[i - 1] + first[i];
    }
    while (times--) {
        int a, b;
        scanf("%d%d", &a, &b);

        printf("%lld\n", second[b]-second[a-1]);
    }
    return 0;
}

int check(int n) {
    int x = 0;
    while (n != 0) {
        if ((n - 1) % 10 == 0) {
            x++;
            n /= 10;
        } else
            n /= 10;
    }
    return x;
}