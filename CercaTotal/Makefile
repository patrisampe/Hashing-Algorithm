cercaTotal.exe: cercaTotal.o ../metodos.o
	g++ -o cercaTotal.exe -std=c++11 -Wall  cercaTotal.o ../metodos.o

cercaTotal.o: cercaTotal.cc
	g++ -c cercaTotal.cc -std=c++11 -Wall  

clean:
	rm *.o
	rm *.exe
