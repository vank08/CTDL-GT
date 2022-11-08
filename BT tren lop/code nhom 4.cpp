#include <iostream>
#include <algorithm>
using namespace std;

void printArr(int Arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

void merge(int X[], int Y[], int m, int n) {
    for (int i = 0; i < m; i++) {
        if (X[i] > Y[0]) {
            swap(X[i], Y[0]);
            int first = Y[0];

            int k;
            for (k = 1; k < n && Y[k] < first; k++) {
                Y[k - 1] = Y[k];
            }

            Y[k - 1] = first;
        }
    }
}

int main() {
    int X[] = { 5, 6, 7, 9, 13 };
    int Y[] = { 2, 4, 24 };

    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);

    merge(X, Y, m, n);

    cout << "X: "; printArr(X, m);
    cout << "Y: "; printArr(Y, n);

    return 0;
}
