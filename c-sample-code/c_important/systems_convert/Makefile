CC = gcc
TARGET = systems_convert
CFLAGS = -std=gnu11  -c
OBJS = main.o systems_convert.o 

$(TARGET):$(OBJS)
	$(CC) $^ -lm -o $(TARGET)
%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

.PHONY:clean	
clean:
	rm *.o $(TARGET) -rf