#include "metodos.h"
using namespace std;

// RADIX SORT

void Metodos::radixSort(VI& v) {
    int m = getMax(v);
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

// QUICKSORT

void Metodos::quicksort(VI& v, int left, int right){
	if (left < right) {
    	int part = partition(v, left, right);
    	quicksort(v, left, part - 1);
    	quicksort(v, part + 1, right);
    }
}

int Metodos::partition(VI& v, int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot = v[mid];
    swap(v[mid],v[left]);
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while(i <= j && v[i] <= pivot) {
            i++;
        }
 
        while(i <= j && v[j] > pivot) {
            j--;
        }
 
        if (i < j) {
            swap(v[i], v[j]);
        }
    }
    swap(v[i - 1],v[left]);
    return i - 1;
}

