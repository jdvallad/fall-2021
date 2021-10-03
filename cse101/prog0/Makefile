CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic
all: prog0

banhammer:
	$(CC) -o prog0 $(pkg-config --cflags --libs cairo) -lm prog0.c

clean:
	rm -f prog0
	rm -f *.o

scan-build: clean
	scan-build make

format: clean
	$(CC)-format -i -style=file *.h
	$(CC)-format -i -style=file *.c
