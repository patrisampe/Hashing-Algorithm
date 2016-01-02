#include <iostream>
#include <fstream>
#include <string>
#include "metodos.h"
#include <math.h>
#include <ctime>

using namespace std;

typedef vector<bool> VI1;
typedef vector<int> VI;
typedef pair<bool,int> PBI;
typedef vector<PBI> PB;
int M;
int A = 0.4;

void usage() {
	cout << "./bloom.exe NomFitxerDiccionari NomFitxerText" << endl;
}

int hash1(int num){
  return num%M;
  
}

int hash2(int num){
  double aux= num*0.21;
  int auxi = aux;
  double dd = aux-auxi;
  double de = dd*M;
  int rr = de;
  return rr;
}

int hash3(int num){
  
    double aux= num*0.67;
  int auxi = aux;
  double dd = aux-auxi;
  double de = dd*M;
  int rr = de;
  
  return rr;
}

int lines(ifstream& file) {
	int lines = 0;
	string line;
	while(getline(file, line)) ++lines;
	file.clear();
	file.seekg(0, file.beg);
	return lines;
}

void leer1(const VI& dic, VI1& v) {
	int n = dic.size();
	for (int i = 0; i < n; ++i) {
	  int aux = dic[i];
	  int n1= hash1(aux);
	  int n2= hash2(aux);
	  int n3= hash3(aux);
	  cout << "PROVAA numero " << aux << endl;
	  v[n1]=true;
	  v[n2]=true;
	  v[n3]=true;
	}
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

void analizar(ifstream& file, const VI& diccionario, PB& dico, VI& text) {
	int n = lines(file);
	int num;
	for (int i = 0; i < n; ++i) {
		file >> num;
		PBI res = buscar(num, diccionario, 0, (int)diccionario.size()-1);
		dico[i]= res;
		text[i]=num;
		//cout << "Buscamos numero " << num; 
		//if (res.first) cout << ", comparaciones " << res.second << endl;
		//else cout << " NOT FOUND" << endl;
	}
} 


void analizar1(const VI& text,const VI1& diccionario, const PB& dico) {
	int n = text.size();
	int num;
	for (int i = 0; i < n; ++i) {
		num = text[i];
		cout << "Buscamos numero " << num ;
		int n1= hash1(num);
		int n2= hash2(num);
		int n3= hash3(num);
		//cout << "resultado " << n1 << " " << n2 << " " << n3;
		
		if(diccionario[n1] and diccionario[n2] and diccionario[n3] ){
		  if(dico[i].first) cout << "Lo encontramos y existe"<<endl;
		  else cout << " Lo encontramos y NO existe"<<endl;
		}
		else cout << " NOT FOUND" << endl;
		
		//PBI res = buscar(num, diccionario, 0, (int)diccionario.size()-1);
		// 
		//if (res.first) cout << ", comparaciones " << res.second << endl;
		//else cout << " NOT FOUND" << endl;
	}
} 


int main(int argc, char *argv[]) {
	if (argc != 3) usage();
	ifstream file1, file2;
	file1.open(argv[1]);
	file2.open(argv[2]);
	cout << "Introduce el valor m: ";
	cin >> M;
	int n = lines(file1);
	VI diccionario(n);
	leer(file1, diccionario);
	Metodos m;
	m.radixSort(diccionario);
	//for (int i = 0; i < n; ++i) cout << diccionario[i] << endl;
	int n1 = lines(file2);
	PB dico(n1);
	VI text(n1);
	analizar(file2, diccionario,dico,text);
	
	
	VI1 diccionario1(M,false);
	leer1(diccionario, diccionario1);
	analizar1(text, diccionario1,dico);
	
	
	file1.close();
	file2.close();
}

