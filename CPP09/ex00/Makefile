NAME = btc

CC = c++

RM = rm -rf

CFLAGS  = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		BitcoinExchange.cpp

OBS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBS)
	$(CC) $(CFLAGS) $(OBS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


