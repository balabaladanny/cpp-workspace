#include <stdio.h>

int main() {
    float x;
    while (scanf("%f", &x) != EOF) {
        int y = *(int*)(&x);
        for (int i = 31; i >= 0; i--) {
            int bit = (1 << i);
            if ((bit & y) != 0)
                putchar('1');
            else
                putchar('0');
        }
        puts("");
    }
}