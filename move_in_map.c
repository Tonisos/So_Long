/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:40:58 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/21 16:41:07 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void move_up(t_data *data)
{
	if (data->map[data->yplayer - 1][data->xplayer] == '0'
		|| data->map[data->yplayer - 1][data->xplayer] == 'C')
	{
		if(data->map[data->yplayer - 1][data->xplayer] == 'C')
			data->plant --;
		data->map[data->yplayer - 1][data->xplayer] = 'P';
		data->map[data->yplayer][data->xplayer] = '0';
		data->nbrmouvement ++;
		init_map(data, data->map);
	}
	if (data->plant == 0 && data->map[data->yplayer - 1][data->xplayer ] == 'E')
	{
		mlx_destroy_window(data->mlx, data->mlx_wind);
		exit_game(data);
	}
}
void move_left(t_data *data)
{
	if (data->map[data->yplayer][data->xplayer - 1] == '0'
		|| data->map[data->yplayer][data->xplayer - 1] == 'C')
	{
		if(data->map[data->yplayer][data->xplayer - 1] == 'C')
			data->plant --;
		data->map[data->yplayer][data->xplayer - 1] = 'P';
		data->map[data->yplayer][data->xplayer] = '0';
		data->nbrmouvement ++;
		init_map(data, data->map);
	}
	if (data->plant == 0 && data->map[data->yplayer][data->xplayer - 1] == 'E')
	{
		mlx_destroy_window(data->mlx, data->mlx_wind);
		exit_game(data);
	}
}

void move_down(t_data *data)
{
	if (data->map[data->yplayer + 1][data->xplayer] == '0'
		|| data->map[data->yplayer + 1][data->xplayer] == 'C')
	{
		if(data->map[data->yplayer + 1][data->xplayer] == 'C')
			data->plant --;
		data->map[data->yplayer + 1][data->xplayer] = 'P';
		data->map[data->yplayer][data->xplayer] = '0';
		data->nbrmouvement ++;
		init_map(data, data->map);
	}
	if (data->plant == 0 && data->map[data->yplayer + 1][data->xplayer] == 'E')
	{
		mlx_destroy_window(data->mlx, data->mlx_wind);
		exit_game(data);
	}
}
void move_right(t_data *data)
{
	if (data->map[data->yplayer][data->xplayer + 1] == '0'
		|| data->map[data->yplayer][data->xplayer + 1] == 'C')
	{
		if(data->map[data->yplayer][data->xplayer + 1] == 'C')
			data->plant --;
		data->map[data->yplayer][data->xplayer + 1] = 'P';
		data->map[data->yplayer][data->xplayer] = '0';
		data->nbrmouvement ++;
		init_map(data, data->map);
	}
	if (data->plant == 0 && data->map[data->yplayer][data->xplayer + 1] == 'E')
	{
		mlx_destroy_window(data->mlx, data->mlx_wind);
		exit_game(data);
	}
}
