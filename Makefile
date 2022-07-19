##
#
## STD::VECTOR IN C
## Rigolo2015, Yannis, 2022
# 
##

CC	=	gcc

SRC		=	src/Cvector_create.c		\
			src/Cvector_clear.c			\
			src/Cvector_push_back.c		\
			src/Cvector_push_front.c	\
			src/Cvector_push_index.c	\
			src/Cvector_pop_index.c		\
			src/Cvector_pop_back.c		\
			src/Cvector_pop_front.c		\
			src/Cvector_show.c			\

OBJ		=	$(SRC:.c=.o)

NAME	=	Cvector

CPPFLAGS	=	-I./include

CFLAGS	=	-Werror -Wextra

COVER		=	--coverage

CRITERION	=	-lcriterion

TEST_NAME	=	unit_tests

SRC_TEST	=	tests/unit_tests/basic_tests.c	\
				$(SRC)							\

OBJ_TEST	=	$(SRC_TEST:.c=.o)

GCDA		=	*.gcda
GCNO		=	*.gcno

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(CPPFLAGS) $(CLIBS)

tests_run:	$(OBJ_TEST)
	$(MAKE) fclean
	$(CC) -o $(TEST_NAME) $(COVER) $(CPPFLAGS) $(SRC_TEST) $(CRITERION)
	./$(TEST_NAME)

debug:	CPPFLAGS += -g3
debug:	$(NAME)

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

.PHONY: all debug tests_clean clean fclean re
