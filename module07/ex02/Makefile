NAME = array

CPP = g++
FLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

src = main.cpp
obj_dir = obj/
obj = $(addprefix $(obj_dir), $(src:.cpp=.o))

all: $(NAME)

$(obj_dir)%.o: %.cpp
	mkdir -p $(obj_dir)
	$(CPP) $(FLAGS) -c $< -o $@

$(NAME): $(obj)
	$(CPP) $(FLAGS)  $^ -o $@

clean:
	$(RM) $(obj_dir)

fclean: clean
	$(RM) $(NAME)

re: fclean all
