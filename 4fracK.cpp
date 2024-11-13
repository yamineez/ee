#include <iostream>
using namespace std;

struct Items {
    int profit;
    int weight;
};

void bubbleSort(int n, double ratio[], Items item[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (ratio[j] < ratio[j + 1]) {
                double tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                Items tempItem = item[j];
                item[j] = item[j + 1];
                item[j + 1] = tempItem;
            }
        }
    }
}

double calcM(int n, int maxWeight, Items item[]) {
    double ratio[n];

    for (int i = 0; i < n; i++) {
        ratio[i] = (double)item[i].profit / item[i].weight;
    }

    bubbleSort(n, ratio, item);

    double maxProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + item[i].weight <= maxWeight) {
            currentWeight += item[i].weight;
            maxProfit += item[i].profit;
        } else {
            int remainingWeight = maxWeight - currentWeight;
            maxProfit += item[i].profit * ((double)remainingWeight / item[i].weight);
            break;
        }
    }

    return maxProfit;
}

int main() {
    int n, maxWeight;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> maxWeight;

    Items item[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> item[i].profit >> item[i].weight;
    }

    double maxProfit = calcM(n, maxWeight, item);
    cout << "The maximum profit is: " << maxProfit << endl;

    return 0;
}
