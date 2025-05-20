#include <stdio.h>
#define V 4
#define INF 999

int tsp(int g[V][V], int v[V], int pos, int n, int count, int cost, int ans) {
    if (count == n && g[pos][0]) {
        if (ans > cost + g[pos][0])
            ans = cost + g[pos][0];
        return ans;
    }

    for (int i = 0; i < n; i++) {
        if (!v[i] && g[pos][i]) {
            v[i] = 1;
            ans = tsp(g, v, i, n, count + 1, cost + g[pos][i], ans);
            v[i] = 0;
        }
    }

    return ans;
}

int main() {
    int g[V][V], v[V];
    int n;

    printf("Enter order of graph matrix: ");
    scanf("%d", &n);

    printf("Enter graph matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    for (int i = 0; i < n; i++)
        v[i] = 0;

    v[0] = 1;

    int ans = tsp(g, v, 0, n, 1, 0, INF);
    printf("Minimum Cost = %d\n", ans);

    return 0;
}
