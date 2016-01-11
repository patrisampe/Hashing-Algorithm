bloom.exe: bloom.o metodos.o
	g++ -o bloom.exe -std=c++11 -Wall  *.o

metodos.o: metodos.h metodos.cc
	g++ -c metodos.cc -std=c++11 -Wall

bloom.o: blomm.cc metodos.h
	g++ -c blomm.cc -std=c++11 -Wall  

clean:
	rm *.o
	rm *.exe
