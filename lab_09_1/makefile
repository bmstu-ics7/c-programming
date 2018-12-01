KEYS := -std=c99 -Wall -Werror
CC := gcc
RM := rm

GRAPH := 500 10

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

graphtest: tick.o my_strpbrk.o graph.o
	$(CC) -o graphtest.exe $^
	./graphtest.exe $(GRAPH)
	python3 graph.py

clean:
	$(RM) *.o *.exe *.gch

