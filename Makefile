prueba.exe: prueba.o metodos.o
	g++ -o prueba.exe -std=c++11 -Wall  *.o

metodos.o: metodos.h metodos.cc
	g++ -c metodos.cc -std=c++11 -Wall

prueba.o: prueba.cc metodos.h
	g++ -c prueba.cc -std=c++11 -Wall  

clean:
	rm *.o
	rm *.exe
