#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;

class Metodos {
public:
	void radixSort(VI& v);
	void quicksort(VI& v, int left, int right);
private:
	void countingSort(VI& v, int exp);
	int getMax(const VI& v);
	int partition(VI& v, int left, int right);
};