##
#
## STD::VECTOR IN C
## Rigolo2015, Yannis, 2022
# 
##

CC	=	gcc

##?				NORMAL TESTS
SRC		=	src/vector_create.c			\
			src/vector_clear.c			\
			src/vector_push_back.c		\
			src/vector_push_front.c		\
			src/vector_push_index.c		\
			src/vector_pop_index.c		\
			src/vector_pop_back.c		\
			src/vector_pop_front.c		\
			src/vector_show.c			\

OBJ		=	$(SRC:.c=.o)

NAME	=	project

CPPFLAGS	=	-I./include -Wextra
#!#######################################################

##?				UNIT TESTS
COVER		=	--coverage

CRITERION	=	-lcriterion

TEST_NAME	=	unit_tests

SRC_TEST	=	tests/unit_tests/basic_tests.c	\
				$(SRC)							\

OBJ_TEST	=	$(SRC_TEST:.c=.o)

GCDA		=	*.gcda
GCNO		=	*.gcno
#!#######################################################

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(CPPFLAGS) $(CLIBS)

tests_run:	$(OBJ_TEST)
	make fclean
	$(CC) -o $(TEST_NAME) $(COVER) $(CPPFLAGS) $(SRC_TEST) $(CRITERION)
	./$(TEST_NAME)

tests_clean:
	rm -f $(OBJ_TEST)
	rm -f $(GCDA)
	rm -f $(GCNO)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)
	find -name '*.gcda' -delete
	find -name '*.gcno' -delete

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re:	fclean all

.PHONY: all clean fclean re
