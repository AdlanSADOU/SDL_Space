##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME    	=       rpg

SRC     	=       $(shell find . -name '*.cpp')

OBJ     	=       $(SRC:.cpp=.o)

CXXFLAGS  	+=      -Wall -Wextra -Wno-unused-parameter

CXXFLAGS 	+=      -I./include -I./vendor/SDL2/include -I./include/imgui \
					-I./include/Framework -I./vendor/SDL2_ttf/include

all     	:       $(NAME)

$(NAME) 	:       $(OBJ)
					g++ -o $(NAME) $(OBJ) -g -O0 -l SDL2 -l SDL2_image

clean   	:
					find . -name "*.o" -type f -delete
					find . -name "vgcore.*" -type f -delete

fclean  	:		clean
					rm -f $(NAME)

re      	:       fclean all


launch		:		re clean
					clear
					./$(NAME)

vg			:		re clean
					clear
					valgrind ./$(NAME)
