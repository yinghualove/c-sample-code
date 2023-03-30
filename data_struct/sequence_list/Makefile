CC = gcc
TARGET = seqlist
CFLAGS = -std=gnu11 -c
OBJS = main.o seq_list_ops.o 

$(TARGET):$(OBJS)
	$(CC) $^ -o $(TARGET)
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

.PHONY:clean	
clean:
	rm *.o $(TARGET) -rf