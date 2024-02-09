CC = gcc
EXEC = path
SRC=$(shell find . -name '*.c')
OBJ=$(patsubst %.c, %.o, $(SRC))

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $^ -o $@

%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm -rf $(OBJ)

mrproper : clean
	rm -rf $(EXEC)