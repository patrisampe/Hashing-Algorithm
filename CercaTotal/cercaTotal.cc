#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <ctime>
#include "metodos.h"
using namespace std;

typedef vector<int> VI;

void usage() {
	cout << "./cercaTotal.exe NomFitxerDiccionari NomFitxerText" << endl;
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

void analizarTodo(ifstream& file, const VI& diccionario, const VI& texto) {
	int i, j, comps;
	i = j = comps = 0;
	int encontrados = 0;
	int N = texto.size();
	int n = diccionario.size();
	while (i < N and j < n) {
		if (texto[i] == diccionario[j]) {++i; ++encontrados;}
		else if (texto[i] < diccionario[j]) ++i;
		else ++j;
		++comps;
	}
	cout << "Numero toal de comparaciones: " << comps << endl;
	cout << "Elementos encontrados: " << encontrados << endl;
} 

int main(int argc, char *argv[]) {
	if (argc != 3) usage();
	ifstream file1, file2;
	file1.open(argv[1]);
	file2.open(argv[2]);
	int n = lines(file1);
	VI diccionario(n);
	leer(file1, diccionario);
	n = lines(file2);
	VI texto(n);
	leer(file2, texto);

	int start_s = clock();
	Metodos m;
	m.radixSort(diccionario);
	m.radixSort(texto);
	int stop_s = clock();
	cout << "time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;

	for (int i = 0; i < 9; ++i) cout << diccionario[i] << endl;
	cout << endl;
	for (int i = 0; i < 11; ++i) cout << texto[i] << endl;
	analizarTodo(file2, diccionario, texto);
	file1.close();
	file2.close();
}

