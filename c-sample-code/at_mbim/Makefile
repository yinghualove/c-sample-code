CC = gcc
TARGET = at_mbim
CFLAGS = -std=gnu11 -c 
OBJS = main.o cmd_match.o at_thread.o at_procs.o

$(TARGET):$(OBJS)
	$(CC) $^ -lpthread -o $(TARGET)
%.o:%.c
	$(CC) $^ $(CFLAGS)  -o $@ 

.PHONY:clean	
clean:
	rm *.o $(TARGET) -rf