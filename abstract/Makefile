NAME = testMyClasses

SRC = AMyStream.cpp \
		 MyDebug.cpp \
		 MyTools.cpp \
		 MyDisplay.cpp \
		 test.cpp

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

#########################################################################
# git push
.PHONY: push
push:		ppush repos

# git push end-of-day
.PHONY: pushend
pushend:	ppushend repos

# prepare git for rendering
.PHONY: render
render:		prender repos

# git push to all repos
.PHONY: repos
repos:
		${eval DATE = `date "+%Y-%m-%d %Hh%Mm%S"`}
		@REMOTES=$$(git remote); \
		for REMOTE in $$REMOTES; do \
			echo "**** PUSH vers $$REMOTE ****"; \
			git push $$REMOTE; \
			echo "###########################"; \
			echo "# PUSHED $$REMOTE"; \
			echo "###########################"; \
		done; \
		echo "######################################################"; \
		echo "# ${DATE} - pushed"; \
		echo "######################################################"; \

# Debug level request if test commpilation
COMMSG		?= ${shell bash -c 'read -p "Message de commit: " commsg; echo $$commsg'}
	
# prepare Git push 
.PHONY: ppush
ppush:		fclean
		${eval DATE = `date "+%Y-%m-%d %Hh%Mm%S"`}
		git add -A
		git commit -m "${DATE} ${COMMSG} - make push"

# prepare End of day git push
.PHONY: ppushend
ppushend:	fclean
		${eval DATE = `date "+%Y-%m-%d %Hh%Mm%S"`}
		git add -A
		git commit -m "${DATE} - make pushend"

# prepare Git push for rendering
.PHONY: prender
prender:	fclean
		${eval DATE = `date "+%Y-%m-%d %Hh%Mm%S"`}
		git add -A
		${IGNORE} ${OBJS} || true
		${IGNORE} ${TSTFIL} || true
		${IGNORE} *pdf || true
		${IGNORE} *txt || true
		${IGNORE} gnl${SVFILE} || true
		${IGNORE} ./vers || true
		${IGNORE} ${SVFILE} || true
		git commit -m "${DATE} - make render"

.PHONY: ask
ask:	fclean
	@cat Makefile > ask.txt
	@cat *hpp >> ask.txt	
	@cat *tpp >> ask.txt	
	@cat *cpp >> ask.txt	

