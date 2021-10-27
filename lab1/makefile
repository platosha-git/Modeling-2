all: app.exe

app.exe: main.o gnuplot.o uniform.o poisson.o
	g++ -o app.exe main.o gnuplot.o uniform.o poisson.o

app.out: main.o gnuplot.o uniform.o poisson.o
	g++ -o app.out main.o gnuplot.o uniform.o poisson.o

main.o: main.cpp uniform.h poisson.h
	g++ -Wall -Werror -lm -c -pedantic main.cpp

gnuplot.o: gnuplot.cpp gnuplot.h
	g++ -Wall -Werror -c -pedantic gnuplot.cpp

uniform.o: uniform.cpp uniform.h gnuplot.h
	g++ -Wall -Werror -lm -c -pedantic uniform.cpp
	
poisson.o: poisson.cpp poisson.h gnuplot.h
	g++ -Wall -Werror -lm -c -pedantic poisson.cpp

clean:
	rm *.o *.exe
