CC=gcc

KEYS= -std=c99 -Wall -Werror

ifeq ($(mode), debug)

	KEYS += -g3

endif



ifeq ($(mode), release)
    
	KEYS += -g0

endif




%.o: %.c %.h
 
	$(CC) $(KEYS) -c $^



app.exe: input_array.o deg_mat.o print_array.o main.o

	$(CC) -o app.exe $^



clean:

	rm *.o *.exe *.gch


test_deg_mat: deg_mat.o test_deg_mat.o
	$(CC) -o test_deg.exe $^