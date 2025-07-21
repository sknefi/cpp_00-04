NAME = harlFilter 

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Harl.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: fclean all

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re