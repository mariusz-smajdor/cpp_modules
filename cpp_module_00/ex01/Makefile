NAME = phone_book
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp Contact/Contact.class.cpp PhoneBook/PhoneBook.class.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re