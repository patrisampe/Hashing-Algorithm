#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <time.h>

using namespace std;

typedef list<int> L;
typedef vector<L> PB;
typedef pair<bool,int> PBI;
typedef pair<double,double> temps;
typedef pair<temps,temps> dd;
typedef vector<int> VI;

int M;
int A = 0.4;
double costHash = 0.0;
double costcomp = 0.0;
int cm = 0;
int hm = 0;

void usage() {
	cout << "./hashtable.exe NomFitxerDiccionari NomFitxerText" << endl;
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



void leer(VI& dict, PB& v) {
	int n = dict.size();
	int num;
	for (int i = 0; i < n; ++i) {
		num= dict[i];
		int n1 = hash1(num);
		list<int>::iterator it =v[n1].begin();
		v[n1].insert(it,num);
	}
}

PBI buscar(int x, L mylist ) {
	//;
	int d =0;
	for(list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it){
	  
	  int start_s = clock();
	  double aa = *it ==x;
	  //leer(file1, diccionario);
	  int stop_s = clock();
	  double timeaux= (stop_s - start_s)/double(CLOCKS_PER_SEC);
	  costcomp = costcomp + timeaux;
	  cm = cm+1;
	  d= d+1;
	  
	  
	  if(aa)return PBI(true,d);
	}
	return PBI(false, d);
}

void leertexto(ifstream& file, VI& text) {
	int n = lines(file);
	//int num;
	for (int i = 0; i < n; ++i) {
		file >> text[i];
		//PBI res = buscar(num, diccionario, 0, (int)diccionario.size()-1);
		//dico[i]= res;
		//text[i]=num;
		//cout << "Buscamos numero " << num; 
		//if (res.first) cout << ", comparaciones " << res.second << endl;
		//else cout << " NOT FOUND" << endl;
	}
} 

dd analizar(VI& text, const PB& diccionario) {
	//int n = lines(file);
	int num;
	double bo= 0.0;
	double dolent = 0.0;
	double cbo= 0.0;
	double cdolent = 0.0;
	int dbo = 0;
	int ddolent = 0;
	int n = text.size();
	for (int i = 0; i < n; ++i) {
		num= text[i];
		
            	int start_s = clock();
		int h = hash1(num);
	  //leer(file1, diccionario);
		int stop_s = clock();
		double timeaux= (stop_s - start_s)/double(CLOCKS_PER_SEC);
		costHash = costHash + timeaux;
		hm = hm+1;
		
		start_s = clock();
		PBI res = buscar(num, diccionario[h]);
		stop_s = clock();
		double dif = (stop_s - start_s)/double(CLOCKS_PER_SEC);
		//cout << "Buscamos numero " << num; 
		if (res.first) {
		  bo = bo+dif;
		  //cout << "TROBAT ";
		  cbo = cbo+res.second;
		  dbo = dbo +1;
		  
		}
		  else {
		    
		    dolent = dolent +dif;//cout << " NOT FOUND" << endl;
		    cdolent = cdolent +res.second;
		    ddolent = ddolent +1;
		  }
		 // cout << ", comparaciones " << res.second << endl;
	}
	if(dbo> 0)bo = bo /dbo;
	if(ddolent>0)dolent = dolent/ddolent;
	if(dbo> 0)cbo = cbo/dbo;
	if(ddolent>0)cdolent = cdolent/ddolent;
	//cout << "HELP " << bo << " " << dolent<< " " << cbo << " " << cdolent<<endl;
	return dd(temps(bo,dolent),temps(cbo,cdolent));
} 


int main(int argc, char *argv[]) {
	if (argc != 6) usage();
	srand(time(0));
	ifstream file1, file2;
	file1.open(argv[1]);
	file2.open(argv[2]);
	//cout << "Introduce el valor m: ";
	//cin >> M;
	int n = lines(file1);
	int n2 = lines(file2);
	double timecrear = 0.0;
	  double timebuscarbo = 0.0;
	   double timebuscardolent = 0.0;
	double cbo= 0.0;
	double cdolent= 0.0;
	VI texto(n2);
	leertexto(file2,texto);
	VI dict(n);
	leertexto(file1,dict);
	int j = 1;
	//for(int i =1; i<=n;++i){
	   
//	for(int i = 1;i<=n;++i){
	 // if(i> 100)i = 13*i+17;
	 // M = i;

	M =n+1049;
	  PB diccionario(M);
	  int start_s = clock();
	  leer(dict, diccionario);
	  int stop_s = clock();
	  double timeaux= (stop_s - start_s)/double(CLOCKS_PER_SEC);
	  timecrear = timecrear + timeaux;
	 // start_s = clock();
	  //cout << M << ","<<timeaux
	  dd auxi= analizar(texto, diccionario);
	   //stop_s = clock();
	  temps aux = auxi.first;
	  temps comp = auxi.second;
	  //cout << M << ","<<timeaux<<","<<aux.first<<","<<aux.second<<"," <<comp.first <<"," << comp.second<<endl;
	   timebuscarbo = timebuscarbo + aux.first;
	   timebuscardolent = timebuscardolent + aux.second;
	   cbo = cbo+comp.first;
	   cdolent = cdolent +comp.second;
	  // j = j+1;
	//}
	j = 1;
	timecrear=timecrear/j;
	timebuscarbo=timebuscarbo/j;
	timebuscardolent=timebuscardolent/j;
	cbo = cbo/j;
	cdolent = cdolent/j;
	cout << argv[3] << ", "<< argv[4] << " ," <<argv[4]<< " ,";
	
	cout << timecrear << ", " << timebuscarbo << " , " << timebuscardolent << " ,"<< timebuscarbo+timebuscardolent<<" , " << cbo << " , " << cdolent << " , " << cbo+cdolent << " ," <<costcomp/cm << " , " << costHash/hm << endl;
	costHash = costHash/hm;
	costcomp = costcomp/cm;
	//cout << " cost hash " << costHash << " cost comparacio " << costcomp << endl;
	
	file1.close();
	file2.close();
}