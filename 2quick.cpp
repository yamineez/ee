#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int a[], int l, int h) {
    int p = a[h];
    int i = l - 1;
    for (int j = l; j < h; j++) {
        if (a[j] < p) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    return i + 1;
}

void quickS(int a[], int l, int h) {
    if (l < h) {
        int p = partition(a, l, h);
        quickS(a, l, p - 1);
        quickS(a, p + 1, h);
    }
}

int main() {
    int s;
    cin >> s;

    int a[s];
    for (int i = 0; i < s; i++) {
        cin >> a[i];
    }

    quickS(a, 0, s - 1);
    for (int i = 0; i < s; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
