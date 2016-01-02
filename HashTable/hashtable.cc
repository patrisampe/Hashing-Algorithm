#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <list>
#include <vector>
#include <ctime>

using namespace std;

typedef list<int> L;
typedef vector<L> PB;
typedef pair<bool,int> PBI;
int M;
int A = 0.4;

void usage() {
	cout << "./bloom.exe NomFitxerDiccionari NomFitxerText" << endl;
}

int hash1(int num){
  return num%M;
  
}


int lines(ifstream& file) {
	int lines = 0;
	string line;
	while(getline(file, line)) ++lines;
	file.clear();
	file.seekg(0, file.beg);
	return lines;
}


void leer(ifstream& file, PB& v) {
	int n = lines(file);
	int num;
	for (int i = 0; i < n; ++i) {
		file >> num;
		int n1 = hash1(num);
		list<int>::iterator it =v[n1].begin();
		v[n1].insert(it,num);
	}
}

PBI buscar(int x, L mylist ) {
	//;
	int d =0;
	for(list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it){
	  
	  d= d+1;
	  if(*it == x)return PBI(true,d);
	}
	return PBI(false, d);
}

void analizar(ifstream& file, const PB& diccionario) {
	int n = lines(file);
	int num;
	for (int i = 0; i < n; ++i) {
		file >> num;
		int h = hash1(num);
		
		PBI res = buscar(num, diccionario[h]);
		cout << "Buscamos numero " << num; 
		if (res.first) cout << "TROBAT ";
		else cout << " NOT FOUND" << endl;
		 cout << ", comparaciones " << res.second << endl;
	}
} 


int main(int argc, char *argv[]) {
	if (argc != 3) usage();
	ifstream file1, file2;
	file1.open(argv[1]);
	file2.open(argv[2]);
	cout << "Introduce el valor m: ";
	cin >> M;
	
	PB diccionario(M);
	int start_s = clock();
	leer(file1, diccionario);
	int stop_s = clock();
	cout << " time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC);
	
	//Metodos m;
	//m.radixSort(diccionario);
	//for (int i = 0; i < n; ++i) cout << diccionario[i] << endl;
	//int n1 = lines(file2);
	//PB dico(n1);
	//VI text(n1);
	analizar(file2, diccionario);
	
	
	file1.close();
	file2.close();
}