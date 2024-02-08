CC = gcc
EXEC = path
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $^ -o $@

%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm -rf *.o

mrproper : clean
	rm -rf $(EXEC)