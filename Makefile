CC=g++
CPPFLAGS=-Wall

all: 
	${CC} -Wall -fpic -c -Werror plugin1.cpp
	${CC} -shared -o libplugin1.so plugin1.o
	mv libplugin1.so plugins/
	${CC} main.cpp -o main -ldl -g
clean:
	rm plugin1.o plugins/libplugin1.so main
