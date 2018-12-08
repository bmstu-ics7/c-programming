KEYS := -std=c99 -Wall -Werror
CC := gcc
RM := rm

ifeq ($(mode), debug)
    KEYS += -g3
endif

ifeq ($(mode), release)
    KEYS += -g0
endif

%.o: %.c %.h
	$(CC) $(KEYS) -c $^

build: file.o work.o main.o
	$(CC) -o app.exe $^

run: file.o work.o main.o
	$(CC) -o app.exe $^
	./app.exe test.in

clean:
	$(RM) *.o *.exe *.gch


