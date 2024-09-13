#include <stdio.h>
#define INF 1e10
int tunnel[2005][2005], bridge[2005][2005];
long long int distance_head[2005], distance_tail[2005];

long long int min(long long int a, long long int b) {
    if (a < b)
        return a;
    else
        return b;
}

void Dijkstra(int n, int start) {
    long long int pred[2005];
    long long int visited[2005], count, mindistance, nextnode, i, j;

    // Creating tunnel matrix
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (tunnel[i][j] == 0)
                tunnel[i][j] = INF;
            else
                tunnel[i][j] = tunnel[i][j];

    for (i = 1; i <= n; i++) {
        distance_head[i] = tunnel[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance_head[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n -1) {
        mindistance = INF;

        for (i = 1; i <= n; i++)
            if (distance_head[i] < mindistance && !visited[i]) {
                mindistance = distance_head[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for (i = 1; i <= n; i++)
            if (!visited[i])
                if (mindistance + tunnel[nextnode][i] < distance_head[i]) {
                    distance_head[i] = mindistance + tunnel[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }
}

void Dijkstra_1(int n, int start) {
    long long int pred[2005];
    long long int visited[2005], count, mindistance, nextnode, i, j;

    for (i = 1; i <= n; i++) {
        distance_tail[i] = tunnel[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance_tail[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INF;

        for (i = 1; i <= n; i++)
            if (distance_tail[i] < mindistance && !visited[i]) {
                mindistance = distance_tail[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for (i = 1; i <= n; i++)
            if (!visited[i])
                if (mindistance + tunnel[nextnode][i] < distance_tail[i]) {
                    distance_tail[i] = mindistance + tunnel[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }
}

int main() {
    int n, s, e;
    scanf("%d %d %d", &n, &s, &e);
    int t;
    scanf("%d", &t);
    while (t--) {
        int v, u;
        scanf("%d%d", &v, &u);
        scanf("%d", &tunnel[v][u]);
        tunnel[u][v] = tunnel[v][u];
    }

    Dijkstra(n, s);    //每個點跟頭的距離存在distance_head
    Dijkstra_1(n, e);  //每個點跟尾的距離存在distance_tail
    int b;
    scanf("%d", &b);
    while (b--) {
        int x, y;
        scanf("%d%d", &x, &y);
        scanf("%d", &bridge[x][y]);
        bridge[y][x] = bridge[x][y];
    }

    long long int mini = distance_head[e];  //都沒走bridge的最短距離
    long long int ans = 1e10;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (bridge[i][j] != 0) {  //如果有bridge 就看有沒有比較短 有的話就改ans
                ans = min(distance_head[i] + bridge[i][j] + distance_tail[j], ans);
            }
        }
    }
    ans = min(mini, ans);
    printf("%lld\n", ans);
}

//https://www.programiz.com/dsa/dijkstra-algorithm 這是dijkstra的網站