#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <limits>
using namespace std;

int N;

typedef vector<int> VI;

void input(string& file1, string& file2) {
	cout << "Introduce el valor n: ";
	cin >> N;
	cout << "Introduce el nombre del archivo diccionario: ";
	cin >> file1;
	cout << "Introduce el nombre del archivo texto: ";
	cin >> file2;
}

bool in(int x, const VI& v, int pos) {
	for (int i = 0; i <= pos; ++i) {
		if (x == v[i]) return true;
	}
	return false;
}

void generar_enteros(VI& v) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, numeric_limits<int>::max());
	for (int i = 0; i < N; ++i) {
		int r = dis(gen);
		while (in(r, v, i)) r = dis(gen);
		v[i] = r;
	}
}

void escribir(const VI& enteros, string dic, string text) {
	ofstream file1, file2;
  	file1.open (dic + ".txt");
  	file2.open(text + ".txt");
  	for (int i = 0; i < N; ++i) {
  		file1 << enteros[i] << endl;
  	}
  	for (int i = 0; i < N; ++i) {
  		file2 << enteros[i] << endl;
  		file2 << enteros[i] + 12 << endl;
  		file2 << enteros[i] + 12321 << endl;
  	}
  	file1.close();
  	file2.close();
}

int main() {
	string file1, file2;
	input(file1, file2);
	VI enteros(N);
	generar_enteros(enteros);
	escribir(enteros, file1, file2);
}
