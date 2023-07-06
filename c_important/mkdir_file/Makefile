CC = gcc
TARGET = mkdir_file
CFLAGS = -std=gnu11  -c
OBJS = mkdir_file.o 

$(TARGET):$(OBJS)
	$(CC) $^ -lm -o $(TARGET)
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

.PHONY:clean	
clean:
	rm *.o $(TARGET) -rf