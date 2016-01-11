#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <ctime>
#include "../metodos.h"
using namespace std;

typedef vector<int> VI;

// Mesures
double tiempoTotal = 0.0;
double hit = 0;
double miss = 0;
double comps = 0;

void usage() {
	cout << "./cercaTotal.exe NomFitxerDiccionari NomFitxerText SortingAlgorithm" << endl;
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

void analizarTodo(ifstream& file, const VI& diccionario, const VI& texto) {
	int i, j;
	i = j = 0;
	int N = texto.size();
	int n = diccionario.size();

	int start_s = clock();
	while (i < N and j < n) {
		if (texto[i] == diccionario[j]) {++i; ++hit;}
		else if (texto[i] < diccionario[j]) {++i; ++miss;}
		else ++j;
		comps += 2;
	}
	int stop_s = clock();

	if (i < N) miss += N-i+1;
	tiempoTotal = (stop_s - start_s)/double(CLOCKS_PER_SEC);
} 

int main(int argc, char *argv[]) {
	if (argc != 7) usage();
	ifstream file1, file2;
	file1.open(argv[1]);
	file2.open(argv[2]);
	int n = lines(file1);
	VI diccionario(n);
	leer(file1, diccionario);
	int N = lines(file2);
	VI texto(N);
	leer(file2, texto);

	int start_s;
	int stop_s;
	Metodos m;
	if (string(argv[3]) == "2") {
		start_s = clock();
		m.radixSort(diccionario);
		m.radixSort(texto);
		stop_s = clock();
	}
	else {
		start_s = clock();
		m.quicksort(diccionario, 0, n-1);
		m.quicksort(texto, 0, N-1);
		stop_s = clock();
	}

	analizarTodo(file2, diccionario, texto);
	file1.close();
	file2.close();

	cout << argv[4] << ", "<< argv[5] << " ," <<argv[6]<< " ,";
	cout << (stop_s - start_s)/double(CLOCKS_PER_SEC) << ","
		 << tiempoTotal/(hit+miss) << ","
		 << tiempoTotal/(hit+miss) << ","
		 << tiempoTotal/(hit+miss) << ","
		 << comps/(hit+miss) << ","
		 << comps/(hit+miss) << ","
		 << comps/(hit+miss) << endl;
}

