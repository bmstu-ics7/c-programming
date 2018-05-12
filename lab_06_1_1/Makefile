KEYS := -g0
ERROR := -std=c99 -Wall -Werror
CC := gcc
RM := rm

%.o: %.c
	$(CC) $(ERROR) $(KEYS) -c $^

all: input_array.o calc.o read_error.o main.o
	$(CC) -o app.exe $^

clean:
	$(RM) *.o *.exe
