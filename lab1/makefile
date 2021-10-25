all: app.exe
app.exe: main.o uniform.o
	g++ -o app.exe main.o uniform.o

app.out: main.o uniform.o
	g++ -o app.out main.o uniform.o

main.o: main.cpp uniform.h
	g++ -Wall -Werror -c -pedantic main.cpp

uniform.o: uniform.cpp uniform.h gnuplot.h
	g++ -Wall -Werror -c -pedantic uniform.cpp

clean:
	rm *.o*.exe
