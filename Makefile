CC = gcc
FLAGS = -Wall -Wextra -Wpedantic -std=c11 -D_GNU_SOURCE

ex10: main.o crc32.o
	$(CC) main.o crc32.o -o ex10

main.o: main.c
	$(CC) $(FLAGS) -c main.c -o main.o

crc32.o: crc32.c
	$(CC) $(FLAGS) -c crc32.c -o crc32.o

clean:
	rm -f ex10 *.o
