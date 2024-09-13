#include<iostream>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;

long long eat[200005];
int visited[200005];
std::map<pair<int, long long>, long long> length_remain;
std::map<long long, int> num_count; // Keep track of the count of each number
int n, k;
long long int sum;

int len(long long s) {
    int ans = 0;
    while(s != 0) {
        s /= 10;
        ans++;
    }
    return ans;
}

int main() {
    while(scanf("%d %d", &n, &k) != EOF) {
        length_remain.clear();
        num_count.clear();
        memset(eat, 0, sizeof(eat));
        memset(visited, 0, sizeof(visited));
        sum = 0;

        for(int i = 0; i < n; i++) {
            scanf("%lld", &eat[i]);

            length_remain[{len(eat[i]), eat[i] % k}]++;
        }

        for(int i = 0; i < n; i++) {
            long long temp = eat[i];
            for(int j = 1; j <= 10; j++) {
                temp *= 10;
                temp %= k;
                if(temp == 0) {
                    if (length_remain.find({j, 0}) != length_remain.end())
                        sum += length_remain[{j, 0}];
                    if(len(eat[i]) == j && eat[i] % k == 0) sum--;
                }
                else {
                    if (length_remain.find({j, k - temp}) != length_remain.end())
                        sum += length_remain[{j, k - temp}];
                    if(len(eat[i]) == j && eat[i] % k == k - temp) sum--;
                }
            }
        }
        printf("%lld\n", sum);
    }
}