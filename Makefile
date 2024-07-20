# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 10:19:02 by fbelkaid          #+#    #+#              #
#    Updated: 2024/07/19 00:11:45 by fbelkaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

SRC = ./mandatory/main.c ./mandatory/tools.c ./mandatory/map_checks.c ./mandatory/utils_cheks.c ./mandatory/moves.c  \
    ./mandatory/count_assets.c ./mandatory/draw.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c\
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
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all
