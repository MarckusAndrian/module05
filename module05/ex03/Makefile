NAME = aform

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

OBJ_DIR = obj/
SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all