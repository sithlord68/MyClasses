NAME = testMyClasses

SRC = AMyStream.cpp \
		 MyDebug.cpp \
		 MyTools.cpp \
		 test.cpp
#		 MyDisplay.cpp \

ASK = ask.txt

OBJS = $(SRC:.cpp=.o)

BIN = $(NAME)

CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
CFLAGT = $(CFLAGS) -g3 -D MYDEBUG=1

CC = g++

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

.PHONY: test
test:
	$(CC) $(CFLAGT) -o $(BIN) $(SRC)


.PHONY: debug
debug: test

.PHONY: clean
clean:	
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(RM) $(BIN)
	$(RM) $(ASK)

.PHONY: re
re: fclean all

.PHONY: ask
ask: fclean
	@cat Makefile >$(ASK)
	@cat *?pp >>$(ASK)
