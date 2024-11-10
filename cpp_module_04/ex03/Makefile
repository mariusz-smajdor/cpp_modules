NAME = materia
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
CC = g++
RM = rm -f

SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp ICharacter.cpp Character.cpp	\
	  IMateriaSource.cpp MateriaSource.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
