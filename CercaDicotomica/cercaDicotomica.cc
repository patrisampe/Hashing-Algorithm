#include <iostream>
#include <fstream>
#include <string>
#include "../metodos.h"
using namespace std;

typedef vector<int> VI;
typedef pair<bool,int> PBI;

// Mesures
double tempsHit = 0.0;
double tempsMiss = 0.0;
double compHit = 0;
double compMiss = 0;
int hit = 0;
int miss = 0;

void usage() {
	cout << "./cercaDicotomica.exe NomFitxerDiccionari NomFitxerText SortingAlgorithm" << endl;
	cout << "SortingAlgorithm = 1 usa Quicksort, SortingAlgorithm = 2 usa Radix Sort" << endl;
}

int lines(ifstream& file) {
	int lines = 0;
	string line;
	while(getline(file, line)) ++lines;
	file.clear();
	file.seekg(0, file.beg);
	return lines;
}

void leer(ifstream& file, VI& v) {
	int n = v.size();
	for (int i = 0; i < n; ++i) {
		file >> v[i];
	}
}

PBI buscar(int x, const VI& diccionario) {
	int i = 0;
	int comps = 0;
	int j = (int)diccionario.size() - 1;
	while (i <= j) {
		int mid = i + ((j - i) / 2);
		if (x == diccionario[mid]) return PBI(true, comps+1);
		else if (x < diccionario[mid]) j = mid-1;
		else i = mid+1;
		++comps;
	}
	return PBI(false, comps);
}

void analizar(ifstream& file, const VI& diccionario) {
	int n = lines(file);
	int num;
	for (int i = 0; i < n; ++i) {
		file >> num;

		int start_s = clock();
		PBI res = buscar(num, diccionario);
		int stop_s = clock();
		if (res.first) {
			tempsHit += (stop_s - start_s)/double(CLOCKS_PER_SEC);
			compHit += res.second;
			++hit;
		}
		else {
			tempsMiss += (stop_s - start_s)/double(CLOCKS_PER_SEC);
			compMiss += res.second;
			++miss;
		}
	}
} 

int main(int argc, char *argv[]) {
	if (argc != 4) usage();
	ifstream file1, file2;
	file1.open(argv[1]);
	file2.open(argv[2]);
	int n = lines(file1);
	VI diccionario(n);
	leer(file1, diccionario);
	int start_s;
	int stop_s;
	Metodos m;
	if (string(argv[3]) == "2") {
		start_s = clock();
		m.radixSort(diccionario);
		stop_s = clock();
	}
	else {
		start_s = clock();
		m.quicksort(diccionario, 0, n-1);
		stop_s = clock();
	}

	analizar(file2, diccionario);
	file1.close();
	file2.close();

	cout << (stop_s - start_s)/double(CLOCKS_PER_SEC) << ",";
	if (hit > 0) cout << tempsHit/hit << ",";
	else cout << "0,";
	if (miss > 0) cout << tempsMiss/miss << ",";
	else cout << "0,";
	cout << (tempsHit+tempsMiss)/(hit+miss) << ",";
	if (hit > 0) cout << compHit/hit << ",";
	else cout << "0,";
	if (miss > 0) cout << compMiss/miss << ",";
	else cout << "0,";
	cout << (compHit+compMiss)/(hit+miss) << endl;
}

