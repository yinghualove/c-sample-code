CC = gcc
TARGET = seq_stack
CFLAGS = -std=gnu11 -c -g
OBJS = main.o seq_stack.o 

$(TARGET):$(OBJS)
	$(CC) $^ -o $(TARGET)
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

.PHONY:clean	
clean:
	rm *.o $(TARGET) -rf