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

all: input_array.o key.o mysort.o print_array.o main.o
	$(CC) -o app.exe $^

clean:
	$(RM) *.o *.exe *.gch

test_key: assert.o key.o test_key.o
	$(CC) -o test_key.exe $^

test_mysort: assert.o mysort.o test_mysort.o
	$(CC) -o test_mysort.exe $^
