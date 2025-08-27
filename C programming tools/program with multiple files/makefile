CC = gcc
FLAGS = -Wall -Werror -Wextra

SRC = math.c main.c
OBJ = $(SRC:.c=.o)

all: program

program: $(OBJ)
	$(CC) $(FLAGS) main.o math.o -o program

%.o: %.c math.h
	$(CC) $(FLAGS) -c $< -o $@

# main.o: main.c math.h
# 	$(CC) $(FLAGS) -c main.c -o math.o
# math.o: math.c math.h
# 	$(CC) $(FLAGS) -c main.c -o math.o

clean:
	rm -f program $(OBJ)
