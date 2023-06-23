(CC) = gcc
TARGET = comport
comport: comport.c comportopen.o comportinit.o comportswap.o comportswap.o
	$(CC) comport.c comportopen.o comportinit.o comportswap.o -o comport -Werror -Wall

comportopen.o: comportopen.c
	$(CC) -c comportopen.c

comportinit.o: comportinit.c
	$(CC) -c comportinit.c

comportswap.o: comportswap.h
	$(CC) -c comportswap.c


clean:
	rm -rf *.o $(TARGET)
