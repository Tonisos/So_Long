# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 14:50:30 by amontalb          #+#    #+#              #
#    Updated: 2022/12/22 15:01:36 by amontalb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX_LIB = mlx/libmlx.a

HEADERS = so_long.h minilibx/mlx.h

SOURCES = main.c check_error_map.c create_img.c init_map.c move_in_map.c \
			get_map.c get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
	
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

MLX_FLAGS = -framework OpenGL -framework AppKit

all :    $(NAME)

%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
		${MAKE} -C ./mlx
		$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
	

clean :
	$(RM) $(OBJECTS) 

fclean : clean 
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re 