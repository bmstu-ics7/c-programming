KEYS := -g0
ERROR := -std=c99 -Wall -Werror
CC := gcc
RM := rm

%.o: %.c %.h
	$(CC) $(ERROR) $(KEYS) -c $^

all: input_array.o calc.o read_error.o main.o
	$(CC) -o app.exe $^

clean:
	$(RM) *.o *.exe *.gch

test_input_array: input_array.o test_input_array.o
	$(CC) -o test_input_array.exe $^

test_calc: calc.o test_calc.o 
	$(CC) -o test_calc.exe $^
