/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:50:19 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/22 15:19:52 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"

typedef struct s_data {
	void	*mlx;
	void	*mlx_wind;
	char	**map;
	char	**testmap;
	int		xtestmap;
	int		ytestmap;
	void	*imgplayer;
	int		xplayer;
	int		yplayer;
	int		width;
	int		height;
	int		plant;
	int		nbrmouvement;
	void	*imgwall;
	void	*imgfloor;
	void	*imgplant;
	void	*imgdooropen;
	void	*imgdoor;
}				t_data;

void	create_player(t_data *data, int x, int y);
void	create_door(t_data *data, int x, int y);
void	create_plant(t_data *data, int x, int y);
void	create_wall(t_data *data, int x, int y);
void	create_floor(t_data *data, int x, int y);

void	move_up(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);

int		check_error_map(t_data *data);
int		display_message(char *c);
int		exit_game(t_data *data);
int		check_rec(t_data *data);

char	**get_map(char **argv, t_data *data);
int		init_map(t_data *data, char **map);
void	initial_img(t_data *data);

#endif 