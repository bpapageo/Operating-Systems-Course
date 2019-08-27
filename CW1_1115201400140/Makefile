OBJS	= main.o structures.o
OUT	= product
CC		= g++
FLAGS	= -c -w -Wall

all: t1

main.o: main.cpp structures.h
	$(CC) $(FLAGS) main.cpp
structures.o: main.cpp structures.h
	$(CC) $(FLAGS) structures.cpp
t1: $(OBJS)
	$(CC) $(OBJS) -o $(OUT)

# clean up
clean:
	rm -f $(OBJS) $(OUT)
