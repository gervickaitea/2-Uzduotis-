main:	funkcijos.o
	g++ -o output 2.0V.cpp funkcijos.o
prog:
	g++ -c funkcijos.cpp
clean:
	rm *.o output.exe Studentai_1000.txt Studentai_10000.txt Studentai_100000.txt Studentai_1000000.txt Studentai_10000000.txt Kvaili_.txt Protingi_.txt
