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

app.exe: input_array.o key.o mysort.o print_array.o main.o
	$(CC) -o app.exe $^

clean:
	$(RM) *.o *.exe *.gch

test.exe: assert.o key.o mysort.o test.o
	$(CC) -o test.exe $^
