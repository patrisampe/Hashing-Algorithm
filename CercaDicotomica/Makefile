cercaDicotomica.exe: cercaDicotomica.o metodos.o
	g++ -o cercaDicotomica.exe -std=c++11 -Wall  *.o

metodos.o: metodos.h metodos.cc
	g++ -c metodos.cc -std=c++11 -Wall

cercaDicotomica.o: cercaDicotomica.cc metodos.h
	g++ -c cercaDicotomica.cc -std=c++11 -Wall  

clean:
	rm *.o
	rm *.exe
