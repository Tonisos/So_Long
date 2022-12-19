# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 14:50:30 by amontalb          #+#    #+#              #
#    Updated: 2022/12/19 09:45:03 by amontalb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX_LIB = libmlx.a

HEADERS = so_long.h

SOURCES = main.c 
	
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

MLX_FLAGS = -framework OpenGL -framework AppKit

all :    $(NAME)

$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)
	
%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS) 

fclean : clean 
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re 