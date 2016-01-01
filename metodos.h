#include <vector>
using namespace std;

class Metodos {
public:
	void radixSort(vector<int>& v);
private:
	void countingSort();
	int getMax(const vector<int>& v);
};