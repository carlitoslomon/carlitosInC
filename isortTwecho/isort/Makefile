CC = gcc
CFLAGS = -g -Wall 
LDFLAGS = -g 
isort:
.PHONY:clean 
clean: 	 
	rm -f *.o  a.out core main 
.PHONY:	clean_all
clean_all: 
	rm -f *.o *.o~ *.c~ *.h~ Makefile~  a.out isort core main 
.PHONY: run
run: 
	./isort
.PHONY: valgrind_read
valgrind_read: 
	valgrind --leak-check=yes  ./isort  >> ../README.txt 2>&1
.PHONY: valgrind_run
valgrind_run:
	valgrind --leak-check=yes $ echo $$((21)) | ./isort	
.PHONY: deep_clean 
deep_clean:
	rm -f .*.un~ *.o *.o~ *.c~ *.h~ Makefile~  a.out isort core main
