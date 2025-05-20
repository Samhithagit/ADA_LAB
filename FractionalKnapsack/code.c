#include <stdio.h>

int n = 5;
int weight[10] = {3, 3, 2, 5, 1};   // weights of items
int profit[10] = {10, 15, 10, 12, 8}; // profits of items
int W = 10; // maximum bag capacity

int main() {
    int current_weight = W, i, max_index;
    float total_profit = 0.0;
    int used[10] = {0}; 

    while (current_weight > 0) {
        max_index = -1;
        for (i = 0; i < n; ++i) {
            if (!used[i]) {
                if (max_index == -1 ||
                    (float)profit[i] / weight[i] > (float)profit[max_index] / weight[max_index])
                    max_index = i;
            }
        }

        // If all items are used, break the loop
        if (max_index == -1)
            break;

        used[max_index] = 1;
        current_weight -= weight[max_index];
        total_profit += profit[max_index];

        if (current_weight >= 0) {
            printf("Added object %d (profit = %d, weight = %d) completely. Space left: %d\n",
                   max_index + 1, profit[max_index], weight[max_index], current_weight);
        } else {
            // Take fraction of the item
            float fraction = 1.0 + (float)current_weight / weight[max_index];
            printf("Added %.2f%% (profit = %d, weight = %d) of object %d\n",
                   fraction * 100,
                   profit[max_index], weight[max_index], max_index + 1);

            total_profit -= profit[max_index];
            total_profit += fraction * profit[max_index];
        }
    }

    printf("Total profit earned = %.2f\n", total_profit);
    return 0;
}

