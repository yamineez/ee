#include <iostream>
using namespace std;

void merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int m = lb;
    int b[ub + 1];

    while (i <= mid && j <= ub) {
        if (a[i] < a[j]) {
            b[m] = a[i];
            i++;
        } else {
            b[m] = a[j];
            j++;
        }
        m++;
    }

    while (i <= mid) {
        b[m] = a[i];
        i++;
        m++;
    }

    while (j <= ub) {
        b[m] = a[j];
        j++;
        m++;
    }

    for (int k = lb; k <= ub; k++) {
        a[k] = b[k];
    }
}

void mergesort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (ub + lb) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> a[i];
    }

    mergesort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
