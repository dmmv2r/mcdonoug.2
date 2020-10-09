C = gcc
CFLAGS = -Wall -g

TARGETS = master palin

all: $(TARGETS)

master: master.o
	$(C) $(CFLAGS) -o $@ master.o

palin: palin.o
	$(C) $(CFLAGS) -o $@ palin.o

clean:
	rm -rf *.o $(TARGETS) 
