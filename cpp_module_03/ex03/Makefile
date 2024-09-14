EXEC = exec
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
RM = rm -f

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

all: $(EXEC) clean

$(EXEC): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
