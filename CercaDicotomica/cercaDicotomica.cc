#include <iostream>
#include <fstream>
#include <string>
#include "metodos.h"
using namespace std;

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
	for (int i = 0; i < n; ++i) cout << diccionario[i] << endl;
	file1.close();
	file2.close();
}

