hash.exe: hashtablesensem.o 
	g++ -o hash.exe -std=c++11 -Wall  *.o

hashtablesensem.o: hashtablesensemv2.cc
	g++ -c hashtablesensemv2.cc -std=c++11 -Wall  

clean:
	rm *.o
	rm *.exe
