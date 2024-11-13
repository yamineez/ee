#include <iostream>
using namespace std;

int linear(int a[], int s, int n) {
    for (int i = 0; i < s; i++) {
        if (a[i] == n) {
            return i;
        }
    }
    return -1;
}

int binary(int a[], int l, int r, int n) {
    if (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == n) {
            return m;
        } else if (a[m] > n) {
            return binary(a, l, m - 1, n);
        } else {
            return binary(a, m + 1, r, n);
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int searchNum = 6;
    int linearResult = linear(arr, size, searchNum);
    int binaryResult = binary(arr, 0, size - 1, searchNum);

    cout << "Linear Search Result: " << (linearResult != -1 ? to_string(linearResult) : "Not Found") << endl;
    cout << "Binary Search Result: " << (binaryResult != -1 ? to_string(binaryResult) : "Not Found") << endl;

    return 0;
}
