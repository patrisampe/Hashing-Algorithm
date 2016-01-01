#include "metodos.h"
using namespace std;

void Metodos::radixSort(VI& v) {
    int m = getMax(v);
    cout << "MAX: " << m << endl;
    for (int exp = 1; m/exp > 0; exp *= 10)
        countingSort(v, exp);
}

void Metodos::countingSort(VI& v, int exp)
{
	int n = v.size();
	VI output(n);
	VI count(10, 0);

	for (int i = 0; i < n; ++i)
		count[ (v[i]/exp)%10 ]++;

	for (int i = 1; i < 10; ++i)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; --i)
    {
        output[count[ (v[i]/exp)%10 ] - 1] = v[i];
        count[ (v[i]/exp)%10 ]--;
    }

    for (int i = 0; i < n; ++i)
        v[i] = output[i];
}

int Metodos::getMax(const VI& v) {
	int n = v.size();
	int max = v[0];
	for (int i = 1; i < n; ++i) {
		if (v[i] > max) max = v[i];
	}
	return max;
}