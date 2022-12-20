/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:50:19 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/20 17:02:23 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "Get_next_line/get_next_line.h"
# include "minilibx/mlx.h"



// int	WIN_H = 1080;
// int	WIN_W = 1920;

typedef struct s_data {
	void	*mlx;
	char	**map;
	void	*mlx_wind;
	void	*imgplayer;
	int		xplayer;
	int		yplayer;
	int 	width;
	int 	height;
	int 	plant;
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


void create_player(t_data *data, int x, int y);
void create_door(t_data *data, int x, int y);
void create_plant(t_data *data, int x, int y);
void create_wall(t_data *data, int x, int y);
void create_floor(t_data *data, int x, int y);

void move_up(t_data *data);
void move_left(t_data *data);
void move_down(t_data *data);
void move_right(t_data *data);

int	check_error_map(t_data *data);


char **get_map(char **argv, t_data *data);
int get_width(char **argv);
int check_char(t_data *data, int C, int P, int E);
int get_height(char **argv);
int check_close(t_data *data);
void create_img(t_data *data, char a, int x, int y);
int init_map(t_data *data, char  **map);
void create_player(t_data *data, int x, int y);
// int	handle_input(int keysym, t_data *data, char **map)
#endif 