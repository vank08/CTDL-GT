#include <iostream>

#include "Foods.h"

using namespace std;

int main() {
	int n = 0;
	cin >> n;

	Foods a[100];
	string s;
	double t;
	for (int i = 0; i < n; i++) {
		cout << "Nhap ten Food: " << endl;
		cin >> s;
		a[i].setName(s);
		cout << "Nhap khoi luong:" << endl;
		cin >> t;
		a[i].setWeight(t);
		cout << "Nhap calories:" << endl;
		cin >> t;
		a[i].setCalories(t);
	}

	return 0;
}