# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 10:19:02 by fbelkaid          #+#    #+#              #
#    Updated: 2024/07/22 23:06:55 by fbelkaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ./mandatory/main.c ./mandatory/tools.c ./mandatory/map_checks.c ./mandatory/utils_cheks.c ./mandatory/moves.c  \
    ./mandatory/count_assets.c ./mandatory/draw.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c\
        ./mandatory/game.c
CC = cc

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

MLX = -lmlx -framework OpenGL -framework Appkit

all : ${NAME}

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(MLX) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME) 

re : fclean all
