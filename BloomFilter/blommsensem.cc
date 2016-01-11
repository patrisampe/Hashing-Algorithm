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
typedef pair<double,double> temps;
typedef pair<double,temps> dd;
int M;
int A = 0.4;
double costHash1 = 0.0;
double costHash2 = 0.0;
double costHash3 = 0.0;
double costcomp = 0.0;
int hm1 = 0;
int hm2 = 0;
int hm3 = 0;
int cm = 0;

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
	 // cout << "PROVAA numero " << aux << endl;
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


dd analizar1(const VI& text,const VI1& diccionario, const PB& dico) {
	int n = text.size();
	int num;
	int numfallos=0;
	int numacierto=0;
	double tempi = 0.0;
	//cout << "n " << n << endl;
	for (int i = 0; i < n; ++i) {
		num = text[i];
		//cout << "Buscamos numero " << num ;
		
		int start_s = clock();
		int n1= hash1(num);
		int stop_s = clock();
		double dif1 = (stop_s - start_s)/double(CLOCKS_PER_SEC);
		costHash1 += dif1;
		hm1 += 1;
		
		start_s = clock();
		int n2= hash2(num);
		stop_s = clock();
		double dif2 = (stop_s - start_s)/double(CLOCKS_PER_SEC);
		costHash2 += dif2;
		hm2 += 1;
		
		
		start_s = clock();
		int n3= hash3(num);
		stop_s = clock();
		double dif3 = (stop_s - start_s)/double(CLOCKS_PER_SEC);
		costHash3 += dif3;
		hm3 += 1;
		
	
		start_s = clock();
		bool n4= diccionario[n1] and diccionario[n2] and diccionario[n3];
		stop_s = clock();
		double dif4 = (stop_s - start_s)/double(CLOCKS_PER_SEC);
		costcomp += dif4;
		cm += 1;
		//cout << "resultado " << n1 << " " << n2 << " " << n3;
		tempi += dif1+dif3+dif2+dif4;
		if( n4){
		  if(dico[i].first) numacierto = numacierto +1;
		  else numfallos = numfallos +1;
		}
		else numacierto = numacierto +1;
		
		//PBI res = buscar(num, diccionario, 0, (int)diccionario.size()-1);
		// 
		//if (res.first) cout << ", comparaciones " << res.second << endl;
		//else cout << " NOT FOUND" << endl;
	}
	
	int ny = numacierto+numfallos;
	//cout << numacierto << " " << numfallos<< endl;
	return dd(tempi/ny,temps(numacierto,numfallos));
} 


int main(int argc, char *argv[]) {
	if (argc != 3) usage();
	ifstream file1, file2;
	file1.open(argv[1]);
	file2.open(argv[2]);
	//cout << "Introduce el valor m: ";
	//cin >> M;
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
	
	double timecrear = 0.0;
	double timebuscar = 0.0;
	double fallos=0;
	double aciertos =0;

	int j = 0;
	for(int i = 1;i<=n;++i){
	  if(i> 100)i = 10*i;
	  M = i;
	  
	  int s = clock();
	  VI1 diccionario1(M,false);
	  leer1(diccionario, diccionario1);
	  int d = clock();
	  timecrear = timecrear +(d-s)/double(CLOCKS_PER_SEC);
	  dd aux= analizar1(text, diccionario1,dico);
	  timebuscar = timebuscar + aux.first;
	  temps uu= aux.second;
	  aciertos = aciertos + uu.first;
	 
	  fallos = fallos + uu.second;
	  j = j+1;
	}
	
	timecrear=timecrear/j;
	timebuscar=timebuscar/j;
	fallos = fallos;
	aciertos = aciertos;
	
	
	cout << timecrear << " , " << timebuscar << ", "<< fallos <<", "<< aciertos << " ," << costcomp/cm << " ,"<< costHash1/hm1 << " ,"<< costHash2/hm2 << " ," << costHash3/hm3 << endl;
	//costHash1 = costHash/hm;
	//costcomp = costcomp/cm;
	//cout << " cost hash " << costHash << " cost comparacio " << costcomp << endl;
	
	file1.close();
	file2.close();
	
	
}

