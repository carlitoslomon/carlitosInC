CFLAGS = -Wall -g 
LDFLAGS = -g
LDLIBS = -lm

main: main.o gcd.o prime.o

main.o: main.c prime.h gcd.h

prime.o: prime.c prime.h

gcd.o: gcd.c gcd.h

.PHONY: clean 
clean: 
        rm -f *.o core main
.PHONY: all
all:  clean main
.PHONY: run
run:
        ./main 
