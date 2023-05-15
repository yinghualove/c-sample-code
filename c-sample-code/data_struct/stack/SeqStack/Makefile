CC = gcc
TARGET = linklist
CFLAGS = -std=gnu11 -c -g
OBJS = main.o Seq_Stack.o 

$(TARGET):$(OBJS)
	$(CC) $^ -o $(TARGET)
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

.PHONY:clean	
clean:
	rm *.o $(TARGET) -rf