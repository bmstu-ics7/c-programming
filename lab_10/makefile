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

app.exe: list.o trie.o main.o
	$(CC) -o app.exe $^

<<<<<<< HEAD:lab_10/makefile
test.exe: list.o test.o
=======
test.exe: assert.o my_string.o test.o
>>>>>>> origin/master:lab_09_2/makefile
	$(CC) -o test.exe $^

clean:
	$(RM) *.o *.exe *.gch

