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

app.exe: my_string.o main.o
	$(CC) -o app.exe $^

test.exe: assert.o my_string.o test.o
	$(CC) -o test.exe $^

clean:
	$(RM) *.o *.exe *.gch

