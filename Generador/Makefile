generador.exe: generador.o 
	g++ -o generador.exe -std=c++11 -Wall  *.o

generador.o: generador.cc
	g++ -c generador.cc -std=c++11 -Wall  

clean:
	rm *.o
	rm *.exe
