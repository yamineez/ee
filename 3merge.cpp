#include <iostream>
using namespace std;

// Function to merge two halves of the array in sorted order
void merge(int a[], int lb, int mid, int ub) {
    int i = lb;        // Starting index for left subarray
    int j = mid + 1;   // Starting index for right subarray
    int m = lb;        // Starting index for merged subarray
    int b[ub + 1];     // Temporary array for merging (size should be ub + 1 to handle bounds)

    // Merging elements from both halves
    while (i <= mid && j <= ub) {
        if (a[i] < a[j]) {      // If element in left subarray is smaller
            b[m] = a[i];
            i++;
        } else {                // If element in right subarray is smaller
            b[m] = a[j];
            j++;
        }
        m++;
    }

    // Copy any remaining elements from the left subarray
    while (i <= mid) {
        b[m] = a[i];
        i++;
        m++;
    }

    // Copy any remaining elements from the right subarray
    while (j <= ub) {
        b[m] = a[j];
        j++;
        m++;
    }

    // Copy merged elements back into the original array 'a'
    for (int k = lb; k <= ub; k++) {
        a[k] = b[k];
    }
}

// Recursive function to perform merge sort
void mergesort(int a[], int lb, int ub) {
    if (lb < ub) {                     // If the array has more than one element
        int mid = (ub + lb) / 2;       // Calculate the midpoint

        mergesort(a, lb, mid);         // Sort the left half
        mergesort(a, mid + 1, ub);     // Sort the right half
        merge(a, lb, mid, ub);         // Merge the sorted halves
    }
}

// Main function
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    // Accepting array elements from the user
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> a[i];
    }

    // Sorting the array using merge sort
    mergesort(a, 0, n - 1);

    // Printing the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
