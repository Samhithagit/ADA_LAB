#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int w, int wt[], int val[], int n) {
    if (n == 0 || w == 0)
        return 0;

    if (wt[n - 1] > w)
        return knapsack(w, wt, val, n - 1);

    else
        return max(
            val[n - 1] + knapsack(w - wt[n - 1], wt, val, n - 1),
            knapsack(w, wt, val, n - 1)
        );
}

int main() {
    int n, w;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &val[i]);
    }

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &wt[i]);
    }

    printf("Enter max capacity of knapsack: ");
    scanf("%d", &w);

    int max_value = knapsack(w, wt, val, n);
    printf("Max value in knapsack = %d\n", max_value);

    return 0;
}
