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

test_input_array: assert.o input_array.o test_input_array.o 
	$(CC) -o test_input_array.exe $^

test_calc: assert.o calc.o test_calc.o 
	$(CC) -o test_calc.exe $^
