# if you can't understand this Makefile, you can learn and understand http://nuclear.mutantstargoat.com/articles/make/.
CC = gcc

SRC = $(wildcard *.c) 
OBJ = $(SRC:.c=.o)


LDFLAGS = -lpthread

DiningPhilosophe: $(OBJ)
	$(CC) $^ -o $@  $(LDFLAGS)

# $^ : the target
# $@ : the dependencies
# $< : the first elements of the dependencies;

.PHONY: clean
clean:
	rm  -f DiningPhilosophe $(OBJ)