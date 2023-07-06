CC = gcc
TARGET = double_linklist
CFLAGS = -std=gnu11 -c -g
OBJS = main.o double_linklist.o

$(TARGET):$(OBJS)
	$(CC) $^ -o $(TARGET)
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

.PHONY:clean	
clean:
	rm *.o $(TARGET) -rf