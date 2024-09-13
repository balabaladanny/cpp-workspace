#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 100000;

int n;
int dp[MAX_N+1][3];

int main()
{
    // I/O boost
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c + max(dp[i-1][0], dp[i-1][1]);
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
    return 0;
}