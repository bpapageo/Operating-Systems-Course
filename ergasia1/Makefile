OBJS	= mymalloc.o structures.o main.o
OUT	= run
CC		= g++
FLAGS	= -c -w -Wall

all: t1

structures.o: structures.cpp structures.h
	$(CC) $(FLAGS) structures.cpp
mymalloc.o: mymalloc.cpp structures.h mymalloc.h
	$(CC) $(FLAGS) mymalloc.cpp
main.o: main.cpp mymalloc.h
	$(CC) $(FLAGS) main.cpp
t1: $(OBJS)
	$(CC) $(OBJS) -o $(OUT)

# clean up
clean:
	rm -f $(OBJS) $(OUT)
