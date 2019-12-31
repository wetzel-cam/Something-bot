CC=g++
CFLAGS=-I ./lib/aegis.cpp/include

test: ./snippets/Test-file.o
	$(CC) -o test ./snippets/Test-file.o

build: ./src/Something-bot.o
	$(CC) -o run ./src/Something-bot.o $(CFLAGS)