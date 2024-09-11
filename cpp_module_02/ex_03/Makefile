EXEC = fixed
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp Fixed.cpp Point.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Fixed.hpp Point.hpp

all: $(EXEC) clean

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
