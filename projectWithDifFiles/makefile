CC = GCC
FLAGS = -Wall -Werror -Wextra

all: program

program: libphong.a
	$(CC) $(FLAGS) project.c -L. -lphong -o program

libphong.a: math.o math.h
	$(CC) $(FLAGS) -c math.c

clean:
	rm -f project.c