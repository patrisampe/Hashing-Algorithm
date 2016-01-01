prueba.exe: prueba.o metodos.o
	g++ -o -std=c++11 -Wall prueba.exe *.o

metodos.o: metodos.h metodos.cc
	g++ -c -std=c++11 -Wall metodos.cc

prueba.o: prueba.cc metodos.h
	g++ -c -std=c++11 -Wall prueba.cc 

clean:
	rm *.o
	rm *.exe
