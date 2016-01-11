#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;

class Metodos {
public:
	void radixSort(VI& v);
private:
	void countingSort(VI& v, int exp);
	int getMax(const VI& v);
};