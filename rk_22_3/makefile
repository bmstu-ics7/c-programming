CC=gcc

KEYS= -std=c99 -Wall -Werror



%.o: %.c %.h
 
	$(CC) $(KEYS) -c $^



app.exe: input_array.o deg_mat.o main.o

	$(CC) -o app.exe $^



clean:

	rm *.o *.exe *.gch
