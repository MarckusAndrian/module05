NAME = template
CPP  = c++

FLAGS = -Wall -Werror -Wextra -std=c++98
obj_dir = obj/

src = main.cpp
obj = $(addprefix $(obj_dir), $(src:.cpp=.o))

all: $(NAME)

$(obj_dir)%.o: %.cpp
	mkdir -p $(obj_dir)
	$(CPP) $(FLAGS) -c $< -o $@

$(NAME): $(obj)
	$(CPP) $(FLAGS) $^ -o $@

clean:
	rm -rf $(obj_dir)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re