#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <limits>
#include <set>
using namespace std;

typedef set<int> SI;
typedef set<int>::const_iterator IT;

// Varibales globales
int N;
double V;
double P;
string file1, file2;
SI enteros;

// Entrada de los datos
void input() {
	cout << "Introduce el valor n: ";
	cin >> N;
	cout << "Introduce el valor por el que multiplicaremos n para obtener la longitud del texto: ";
	cin >> V;
	cout << "Introduce la proporcion esperada de numeros del diccionario en el texto: ";
	cin >> P;
	cout << "Introduce el nombre del archivo diccionario: ";
	cin >> file1;
	cout << "Introduce el nombre del archivo texto: ";
	cin >> file2;
}

// Generacion de N enteros distintos
void generar_enteros() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, numeric_limits<int>::max());
    while (enteros.size() < N) {
    	int r = dis(gen);
    	enteros.insert(r);
    }
}

// Escritura de los numeros en los ficheros
void escribir() {
	ofstream f1, f2;
  	f1.open (file1 + ".txt");
  	f2.open(file2 + ".txt");
  	for (auto e : enteros) {
  		f1 << e << endl;
  	}
  	random_device rd1, rd2, rd3;
	mt19937 gen1(rd1());
	mt19937 gen2(rd2());
	mt19937 gen3(rd3());
	uniform_real_distribution<double> dis1(0, 100);
	uniform_int_distribution<int> dis2(0, N-1);
	uniform_int_distribution<int> dis3(0, numeric_limits<int>::max());
  	for (int i = 0; i < V*N; ++i) {
	    if (dis1(gen1) < P) {
	    	IT it(enteros.begin());
	    	advance(it, dis2(gen2));
	    	f2 << *it << endl;	
	    }
	    else {
	    	f2 << dis3(gen3) << endl;
	    }
  	}
  	f1.close();
  	f2.close();
}

int main() {
	input();
	generar_enteros();
	escribir();
}
