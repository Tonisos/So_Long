/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:50:19 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/22 08:06:33 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"

typedef struct s_data {
	void	*mlx;
	void	*mlx_wind;
	char	**map;
	char 	**testmap;
	int		xtestmap;
	int		ytestmap;
	void	*imgplayer;
	int		xplayer;
	int		yplayer;
	int 	width;
	int 	height;
	int 	plant;
	int		nbrmouvement;
}				t_data;



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
int display_message(char *c);
int exit_game(t_data *data);

int check_rec(t_data *data);
char **get_map(char **argv, t_data *data);
int get_width(char **argv);
int get_height(char **argv);
int check_close(t_data *data);
void create_img(t_data *data, char a, int x, int y);
int init_map(t_data *data, char  **map);
void create_player(t_data *data, int x, int y);
// int	handle_input(int keysym, t_data *data, char **map)
#endif 