#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int optimalMergePattern(vector<int>& files) {
    int totalCost = 0;

    while (files.size() > 1) {
        sort(files.begin(), files.end());
        int first = files[0];
        int second = files[1];
        int mergeCost = first + second;
        totalCost += mergeCost;
        files.erase(files.begin());
        files.erase(files.begin());
        files.push_back(mergeCost);
    }

    return totalCost;
}

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    vector<int> files(n);
    cout << "Enter the sizes of the files:\n";
    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }

    int minCost = optimalMergePattern(files);
    cout << "The minimum cost to merge all files is: " << minCost << endl;

    return 0;
}
