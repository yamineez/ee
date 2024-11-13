#include <iostream>
using namespace std;

struct Item {
    int profit;
    int weight;
};

//0/1 Knapsack
int knapsack(int n, int W, Item items[]) {
    int dp[n + 1][W + 1];  // Create a 2D array to store results

    //table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  //base case: 0 items or 0 weight capacity
            } else if (items[i - 1].weight <= w) {
                //max of current item wt+ / prev item ?
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].profit);
            } else {
                // If the current item's weight is more than the current weight capacity, don't take it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result is stored in dp[n][W], i.e., the maximum profit
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    Item items[n];  // Array of items
    cout << "Enter the profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit >> items[i].weight;
    }

    // Call the knapsack function and print the result
    int maxProfit = knapsack(n, W, items);
    cout << "Maximum profit that can be obtained: " << maxProfit << endl;

    return 0;
}
