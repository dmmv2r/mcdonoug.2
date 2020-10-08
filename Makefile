all: master palin

mcdonoug.2: master.o
	gcc -Wall -g master.o -o master

master.o: master.c
	gcc -Wall -g -c master.c

mcdonoug.2: palin.o
	gcc -Wall -g palin.o -o palin

palin.o: palin.c
	gcc -Wall -g -c palin.c

clean:
	rm -rf *o mcdonoug.2 master palin
