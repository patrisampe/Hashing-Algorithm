cercaTotal.exe: cercaTotal.o metodos.o
	g++ -o cercaTotal.exe -std=c++11 -Wall  *.o

metodos.o: metodos.h metodos.cc
	g++ -c metodos.cc -std=c++11 -Wall

cercaTotal.o: cercaTotal.cc metodos.h
	g++ -c cercaTotal.cc -std=c++11 -Wall  

clean:
	rm *.o
	rm *.exe
