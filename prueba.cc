#include <iostream>
#include "metodos.h"

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	Metodos m;
	m.radixSort(v);
	for (int i = 0; i < n; ++i) cout << v[i] << endl;
}