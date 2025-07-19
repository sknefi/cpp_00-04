NAME = zombies

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Zombie.cpp zombieHorde.cpp main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: fclean all

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re