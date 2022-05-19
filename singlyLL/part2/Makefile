CC = gcc
CFLAGS = -g -Wall 
INCLUDES = -I ../part1
CFLAGS = -g -Wall $(INCLUDES)
CXXFLAGS = -g WALL $(INCLUDES)
LDFLAGS = -g -L ../part1 
LDLIBS =  -lmylist
revecho: 
.PHONY: clean 
clean: 
	rm -f *.o a.out main core revecho libmylib.a
.PHONY: deepClean 
deepClean: 
	rm -f *.o~ *.c~ *.h~ Makefile~ *.swp
.PHONY: run 
run: 
	./revecho mad lad is not the rad dude
.PHONY: runNoDude
runNoDude: 
	./revecho mad lad is not rad; 
.PHONY: valgrindOutYes
