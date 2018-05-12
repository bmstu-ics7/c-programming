KEYS := -g0
ERROR := -std=c99 -Wall -Werror
CC := gcc
RM := rm

%.o: %.c %.h
	$(CC) $(ERROR) $(KEYS) -c $^

all: *.o
	$(CC) -o app.exe $^

clean:
	$(RM) *.o *.exe *.gch

clean_test:
	$(RM) test/*.o *.exe

clean_all:
	$(RM) *.o *.exe *gch test/*.o

test_input_array: input_array.o test/test_input_array.o
	$(CC) -o test_input_array.exe $^

test_calc: calc.o test/test_calc.o 
	$(CC) -o test_calc.exe $^
