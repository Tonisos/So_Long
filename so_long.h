/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:50:19 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/19 15:48:56 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"



// int	WIN_H = 1080;
// int	WIN_W = 1920;

typedef struct s_data {
	void	*mlx;
	void	*mlx_wind;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map {
	int width;
	int height;
	int xp;
	int yp;
	int xe;
	int ye;
	
	
}				t_map;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

char **get_map(char **argv);
int get_width(char **argv);
int check_char(char **map, int C, int P, int E);

#endif 