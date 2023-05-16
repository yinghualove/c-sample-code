CC = gcc
TARGET = link_stack
CFLAGS = -std=gnu11 -c -g
OBJS = main.o link_stack.o 

$(TARGET):$(OBJS)
	$(CC) $^ -o $(TARGET)
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

.PHONY:clean	
clean:
	rm *.o $(TARGET) -rf