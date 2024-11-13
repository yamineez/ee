#include <iostream>
using namespace std;

struct Items {
    int profit;
    int weight;
};

// Bubble Sort function to sort items by profit-to-weight ratio
void bubbleSort(int n, double ratio[], Items item[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // Swap ratio
                double tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                // Swap corresponding item
                Items tempItem = item[j];
                item[j] = item[j + 1];
                item[j + 1] = tempItem;
            }
        }
    }
}

// Function to calculate maximum profit for the given weight limit
double calcM(int n, int maxWeight, Items item[]) {
    double ratio[n];

    // Calculate profit-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)item[i].profit / item[i].weight;
    }

    // Sort items by descending profit-to-weight ratio
    bubbleSort(n, ratio, item);

    double maxProfit = 0.0;
    int currentWeight = 0;

    // Iterate over items, adding as much of each item as possible
    for (int i = 0; i < n; i++) {
        if (currentWeight + item[i].weight <= maxWeight) {
            // Add entire item if it fits
            currentWeight += item[i].weight;
            maxProfit += item[i].profit;
        } else {
            // Add fractional part of item if only part of it fits
            int remainingWeight = maxWeight - currentWeight;
            maxProfit += item[i].profit * ((double)remainingWeight / item[i].weight);
            break; // Knapsack is full
        }
    }

    return maxProfit;
}

int main() {
    int n, maxWeight;

    // Input number of items and max weight capacity
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> maxWeight;

    Items item[n];

    // Input profit and weight for each item
    for (int i = 0; i < n; i++) {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> item[i].profit >> item[i].weight;
    }

    // Calculate maximum profit and output the result
    double maxProfit = calcM(n, maxWeight, item);
    cout << "The maximum profit is: " << maxProfit << endl;

    return 0;
}
