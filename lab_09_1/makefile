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

test.exe: assert.o my_strpbrk.o test.o
	$(CC) -o test.exe $^

clean:
	$(RM) *.o *.exe *.gch

