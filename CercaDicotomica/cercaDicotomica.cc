#include <iostream>
#include <fstream>
#include <string>
#include "metodos.h"
using namespace std;

typedef vector<int> VI;
typedef pair<bool,int> PBI;

void usage() {
	cout << "./cercaDicotomica.exe NomFitxerDiccionari NomFitxerText" << endl;
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

PBI buscar(int x, const VI& diccionario, int i, int j) {
	if (i > j) return PBI(false, 0);
	int mid = i + ((j - i) / 2);
	if (x < diccionario[mid]) {
		PBI p = buscar(x, diccionario, i, mid-1);
		return PBI(p.first, p.second+1);
	}
	if (x > diccionario[mid]) {
		PBI p = buscar(x, diccionario, mid+1, j);
		return PBI(p.first, p.second+2);
	}
	return PBI(true, 2);
}

void analizar(ifstream& file, const VI& diccionario) {
	int n = lines(file);
	int num;
	for (int i = 0; i < n; ++i) {
		file >> num;
		PBI res = buscar(num, diccionario, 0, (int)diccionario.size()-1);
		cout << "Buscamos numero " << num; 
		if (res.first) cout << ", comparaciones " << res.second << endl;
		else cout << " NOT FOUND" << endl;
	}
} 

int main(int argc, char *argv[]) {
	if (argc != 3) usage();
	ifstream file1, file2;
	file1.open(argv[1]);
	file2.open(argv[2]);
	int n = lines(file1);
	VI diccionario(n);
	leer(file1, diccionario);
	Metodos m;
	m.radixSort(diccionario);
	//for (int i = 0; i < n; ++i) cout << diccionario[i] << endl;
	analizar(file2, diccionario);
	file1.close();
	file2.close();
}

