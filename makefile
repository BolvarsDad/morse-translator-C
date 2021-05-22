CFLAGS=-Wall -Wextra -pedantic
FILES=morse.o file.o wordlist.o

all: morseread morsewrite

morseread: morseread.o $(FILES)
	$(CC) $^ -o $@

morsewrite: morsewrite.o $(FILES)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $^ $(CFLAGS) -c

clean:
	rm *.o
	rm morseread
	rm morsewrite

.PHONY: all clean
