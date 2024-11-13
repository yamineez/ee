#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int optimalMergePattern(vector<int>& files) {
    int totalCost = 0;

    while (files.size() > 1) {
        // Sort the files to find the two smallest
        sort(files.begin(), files.end());

        // Take the two smallest elements
        int first = files[0];
        int second = files[1];

        // Merge the two files
        int mergeCost = first + second;
        totalCost += mergeCost;

        // Remove the merged files and add the new merged file
        files.erase(files.begin());  // Remove the first element
        files.erase(files.begin());  // Remove the second element (new first after erasing)
        files.push_back(mergeCost);  // Add the merged file back to the list
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
