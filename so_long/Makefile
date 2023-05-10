# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 20:23:09 by donghyk2          #+#    #+#              #
#    Updated: 2023/01/29 19:30:30 by donghyk2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

CC				= cc
CFLAGS			= -Wall -Werror -Wextra
MLX				= -Lmlx -lmlx -framework OpenGL -framework Appkit
LIBFT			= -Lsrc/libft -lft
GNL_DIR			= src/get_next_line/

SRC				= main.c check_map.c check_path.c make_display.c key_func.c command_validator.c
GNL				= get_next_line.c get_next_line_utils.c

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

OBJS			= $(SRC:.c=.o)
GNL_OBJS		= $(addprefix $(GNL_DIR), $(GNL:.c=.o))

$(NAME): $(GNL_OBJS) $(OBJS)
	make -C mlx all
	make -sC src/libft all
	$(CC) $(CFLAGS) $(MLX) $(LIBFT) $(GNL_OBJS) $(OBJS) -o $@

all: $(NAME)

clean:
	make -C mlx clean
	make -C src/libft clean
	rm -f $(GNL_OBJS)
	rm -f $(OBJS)

fclean:
	make -C src/libft fclean
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
