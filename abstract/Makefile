NAME = testMyClasses

SRC = AMyStream.cpp \
		 MyDebug.cpp \
		 MyDisplay.cpp \
		 MyTools.cpp \
		 test.cpp

OBJS = $(SRC:.cpp=.o)

BIN = $(NAME)

CFLAGS = -Wall -Wextra -Werror -std=c++98
CFLAGT = $(CFLAGS) -g3 -D MYDEBUG=1

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(BIN) $(OBJS)

.PHONY: test
test:
	$(CC) $(FLAGT) -o $(BIN) $(SRC)


.PHONY: debug
debug: test

.PHONY: clean
clean:	
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(RM) $(BIN)

.PHONY: re
re: fclean all

test:
	$(CC) $(FLAGT) -c $<
