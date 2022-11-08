#include <iostream>
#include <set>
using namespace std;

bool check(int Arr[], int n) {
    set<int> set;

    int t = 0;

    set.insert(0);

    for (int i = 0; i < n; i++) {
        t += Arr[i];

        if (set.find(t) != set.end()) {
            return true;
        }
        else {
            set.insert(t);
        }
    }

    return false;
}

int main() {
    int A[] = { 7, 2, -8, -3, 1, 0 };
    int n = sizeof(A) / sizeof(A[0]);

    check(A, n) ? cout << "Exists" : cout << "Not exist";

    return 0;
}