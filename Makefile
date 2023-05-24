OBJS	= display.o queues.o main.o
SOURCE	= display.c queues.c main.c
HEADER	= display.h queues.h
OUT	= schedulesimulator
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

queues.o: queues.c
	$(CC) $(FLAGS) queues.c 

display.o: display.c
	$(CC) $(FLAGS) display.c

main.o: main.c
	$(CC) $(FLAGS) main.c 


clean:
	rm -f $(OBJS) $(OUT)