CC = clang
OUTPUT = prog0
INPUT = prog0.c
CFLAGS = -Wall -Wextra -Werror -Wpedantic
PACKAGES = -lm `pkg-config --cflags --libs cairo`

all: executable

executable: clean
	 $(CC) $(CFLAGS) $(INPUT) -o $(OUTPUT) $(PACKAGES)

clean:
	rm -f $(OUTPUT)
	rm -f *.o

scan-build: clean
	scan-build make

format: clean
	$(CC)-format -i *.c
