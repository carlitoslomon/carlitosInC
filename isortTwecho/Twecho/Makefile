CC = gcc 
CFLAGS = -g -Wall 
LDFLAGS = -g 
twecho:
.PHONY: clean 
clean: 
	rm -rf *.o a.out core main
.PHONY: clean_all
clean_all: 
	rm -f *.out a.out twecho *.c~ *.o~ *.h~ Makefile~ core main

.PHONY: run
run:
	./twecho mad lad is not rad
.PHONY: valgrind
valgrind:
	valgrind ./twecho
.PHONY: deep_clean
deep_clean:
	rm *.c~ twecho  *.o  a.out twecho *.c~ *.o~ *.h~ Makefile~ .*.un~ .*swp. core main
.PHONY: valgrind_read 
valgrind_read: 
	valgrind --leak-check=yes ./twecho mad lad is not rad  >> ../README.txt 2>&u1
.PHONY: valgrind_write 
valgrind_write: 
	valgrind --leak-check=yes ./twecho mad lad is not rad  >> READMEP2.txt 2>&1 
	cat READMEP2.txt 
	rm -f READMEP2.txt
