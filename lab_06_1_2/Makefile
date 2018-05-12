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
