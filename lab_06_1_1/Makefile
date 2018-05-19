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

all: input_array.o calc.o read_error.o main.o
	$(CC) -o app.exe $^

clean:
	$(RM) *.o *.exe *.gch
