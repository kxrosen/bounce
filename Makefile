CC := gcc
CFLAGS := -Wall -Wextra -O2
SRC := main.c
OBJ := main.o

compile: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o output

$(OBJ): $(SRC)
	$(CC) $(SRC) -c

clean:
	rm main.o output
