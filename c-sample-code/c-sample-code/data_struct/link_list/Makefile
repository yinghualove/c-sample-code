CC = gcc
TARGET = linklist
CFLAGS = -std=gnu11 -c -g
OBJS = main.o link_list.o 

$(TARGET):$(OBJS)
	$(CC) $^ -o $(TARGET)
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

.PHONY:clean	
clean:
	rm *.o $(TARGET) -rf