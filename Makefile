FLAGS = -Wall -Werror -Wextra
SRC = array.cpp \
	array2.cpp \
	class.cpp \
	count_down_by_counting_up.cpp \
	count.cpp \
	pointer.cpp \
	pointer2.cpp \
	pointer3.cpp \
	recursion.cpp \
	recursion2.cpp \
	tempCodeRunnerFile.cpp \
	test.cpp \
	testing.cpp

all: $(SRC)

$(SRC):
	g++ $(FLAGS) $@

# fclean:
# 	rm -rf

