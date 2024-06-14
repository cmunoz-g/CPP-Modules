NAME = materia
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
FOLDER = srcs/
OBJFOLDER = obj/
INCLUDES = inc/
SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS = $(SRCS:%.cpp=$(OBJFOLDER)%.o)

$(OBJFOLDER)%.o: $(FOLDER)%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	@rm -rf $(OBJFOLDER)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
