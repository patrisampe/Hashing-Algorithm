cercaDicotomica.exe: cercaDicotomica.o ../metodos.o
	g++ -o cercaDicotomica.exe -std=c++11 -Wall  cercaDicotomica.o ../metodos.o

cercaDicotomica.o: cercaDicotomica.cc
	g++ -c cercaDicotomica.cc -std=c++11 -Wall
	
clean:
	rm *.o
	rm *.exe
