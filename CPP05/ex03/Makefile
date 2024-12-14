NAME = intern

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJS = $(SRCS:.cpp=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) Executable $(NAME) created.$(RESET)"

%.o: %.cpp
	@echo "$(YELLOW)Compiling $< ... $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "CLeaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Removing executable..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
