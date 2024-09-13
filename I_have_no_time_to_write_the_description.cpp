#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAX_N = 301;
long long a[MAX_N], pre[MAX_N], dp[MAX_N][MAX_N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
        }

        // Initialize dp
        for (int i = 1; i <= n; i++) {
            dp[i][1] = pre[i];
        }

        // Calculate dp
        const long long INF = LLONG_MAX;
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= min(i, k); j++) {
                dp[i][j] = INF;
                for (int alpha = j - 1; alpha < i; alpha++) {
                    dp[i][j] = min(dp[i][j], max(dp[alpha][j - 1], pre[i] - pre[alpha]));
                }
            }
        }

        // Output the answer
        cout << dp[n][k] << "\n";
    }
    return 0;
}
