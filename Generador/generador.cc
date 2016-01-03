#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <limits>
#include <unordered_set>
using namespace std;

typedef unordered_set<int> SI;
typedef unordered_set<int>::const_iterator IT;

// Varibales globales
int N;
double V;
double P;
string file1, file2;
int SEED;
SI enteros;

// Usage
void usage() {
	cout << "Usage:" << endl;
	cout << "Input interactivo: ./generador.exe" << endl;
	cout << "Input directo: ./generador.exe N V P nombreDiccionario nombreTexto SEED" << endl;
}

// Entrada de los datos
void inputInteractivo() {
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
	cout << "Introduce la semilla: ";
	cin >> SEED;
}

void inputDirecto(char *argv[]) {
	N = atoi(argv[1]);
	V = atof(argv[2]);
	P = atof(argv[3]);
	file1 = argv[4];
	file2 = argv[5];
}

// Generacion de N enteros distintos
void generar_enteros() {
    random_device rd;
    mt19937 gen(SEED);
    uniform_int_distribution<int> dis(0, numeric_limits<int>::max());
    cout << "Inicio generacion de los numeros enteros" << endl;
    while ((int)enteros.size() < N) {
    	int r = dis(gen);
    	enteros.insert(r);
    }
    cout << "Fin generacion de los numeros enteros" << endl;
}

// Escritura de los numeros en los ficheros
void escribir() {
	ofstream f1, f2;
  	f1.open (file1 + ".txt");
  	f2.open(file2 + ".txt");
  	cout << "Inicio escritura en el diccionario" << endl;
  	for (auto e : enteros) {
  		f1 << e << endl;
  	}
  	cout << "Fin escritura en el diccionario" << endl;
  	random_device rd1, rd2, rd3;
	mt19937 gen1(SEED);
	mt19937 gen2(SEED);
	mt19937 gen3(SEED);
	uniform_real_distribution<double> dis1(0, 100);
	uniform_int_distribution<int> dis2(0, 10);
	uniform_int_distribution<int> dis3(0, numeric_limits<int>::max());
	IT it(enteros.begin());
	int pos = 0;
	cout << "Inicio escritura en el texto" << endl;
  	for (int i = 0; i < V*N; ++i) {
	    if (dis1(gen1) < P) {
	    	if (pos + 10 >= N - 1) {pos = 0; it = enteros.begin();}
	    	int incr = dis2(gen2);
	    	pos = pos + incr;
	    	advance(it, incr);
	    	f2 << *it << endl;	
	    }
	    else {
	    	f2 << dis3(gen3) << endl;
	    }
  	}
  	cout << "Fin escritura en el texto" << endl;
  	f1.close();
  	f2.close();
}

int main(int argc, char *argv[]) {
	if (argc == 1) inputInteractivo();
	else if (argc == 7) inputDirecto(argv);
	else {usage(); return 0;}
	generar_enteros();
	escribir();
}
