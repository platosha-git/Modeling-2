all: app.exe

app.exe: main.o gnuplot.o uniform.o gauss.o
	g++ -o app.exe main.o gnuplot.o uniform.o gauss.o

app.out: main.o gnuplot.o uniform.o gauss.o
	g++ -o app.out main.o gnuplot.o uniform.o gauss.o

main.o: main.cpp uniform.h gauss.h
	g++ -Wall -Werror -lm -c -pedantic main.cpp

gnuplot.o: gnuplot.cpp gnuplot.h
	g++ -Wall -Werror -c -pedantic gnuplot.cpp

uniform.o: uniform.cpp uniform.h gnuplot.h
	g++ -Wall -Werror -lm -c -pedantic uniform.cpp
	
gauss.o: gauss.cpp gauss.h gnuplot.h
	g++ -Wall -Werror -lm -c -pedantic gauss.cpp

clean:
	rm *.o *.exe
