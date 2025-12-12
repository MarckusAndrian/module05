NAME = convert

cpp = c++
flags = -Wall -Werror -Wextra -std=c++98
src = main.cpp ScalarConvert.cpp
obj_dir = obj/
obj = $(addprefix $(obj_dir), $(src:.cpp=.o))

all: $(NAME)

$(obj_dir)%.o: %.cpp
	mkdir -p $(obj_dir)
	$(cpp) $(flags) -c $< -o $@

$(NAME): $(obj)
	$(cpp) $(flags) $^ -o $@

clean:
	rm -rf $(obj_dir)

fclean: clean
	rm -rf $(NAME)

re: fclean all