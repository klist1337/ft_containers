NAME = ft_containers

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address 

OBJ = $(SRC:.cpp=.o)

SRC = main.cpp

RM = rm -rf 

all : $(NAME)

$(NAME): $(OBJ)
				@echo "Compiling..."
				@$(CPP) $(FLAGS) $(OBJ) -o $@
				@echo "Done !"

%.o: %.cpp
			@$(CPP) $(FLAGS) $< -c
			@echo "Compiling..."
clean:
			@$(RM) *.o
			@echo "Cleaning..."
fclean : clean
				@$(RM) $(NAME)
				@echo "Cleaning..."
re : fclean all
