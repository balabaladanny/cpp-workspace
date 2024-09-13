#include <iostream>

int main()
{
    int n, m, A, ans = 1000000001;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n*m; ++i)
        scanf("%d", &A), ans = (ans < A) ? ans : A;
    printf("%d\n", ans);
}