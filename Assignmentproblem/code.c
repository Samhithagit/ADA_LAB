#include <stdio.h>
#define MAX 10

int cost[MAX][MAX], n, minCost = 9999;
int bestAssign[MAX], tempAssign[MAX];

void solve(int a, int currentCost) {
    if (a == n) {
        if (currentCost < minCost) {
            minCost = currentCost;
            for (int i = 0; i < n; i++) {
                bestAssign[i] = tempAssign[i];
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        int isAssigned = 0;
        for (int j = 0; j < a; j++) {
            if (tempAssign[j] == i) {
                isAssigned = 1;
                break;
            }
        }
        if (!isAssigned) {
            tempAssign[a] = i;
            solve(a + 1, currentCost + cost[a][i]);
        }
    }
}

int main() {
    printf("Enter no. of jobs: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    solve(0, 0);

    printf("Optimal assignment cost: %d\n", minCost);
    for (int i = 0; i < n; i++) {
        printf("Worker %d -> Job %d\n", i + 1, bestAssign[i] + 1);
    }

    return 0;
}
