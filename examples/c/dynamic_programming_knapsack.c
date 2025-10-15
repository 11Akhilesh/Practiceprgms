#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static int knapsack(int capacity, const int weights[], const int values[], int count) {
    int dp[count + 1][capacity + 1];
    for (int i = 0; i <= count; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = MAX(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[count][capacity];
}

int main(void) {
    const int weights[] = {2, 3, 4, 5};
    const int values[] = {3, 4, 5, 8};
    const int capacity = 8;
    const int count = sizeof(weights) / sizeof(weights[0]);
    int result = knapsack(capacity, weights, values, count);
    printf("Maximum value: %d
", result);
    return 0;
}
