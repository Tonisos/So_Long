/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_in_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:40:58 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/20 16:30:46 by amontalb         ###   ########.fr       */
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
		init_map(data, data->map);
	}
	if (data->plant == 0 && data->map[data->yplayer - 1][data->xplayer ] == 'E')
		 mlx_destroy_window(data->mlx, data->mlx_wind);
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
		init_map(data, data->map);
	}
	if (data->plant == 0 && data->map[data->yplayer][data->xplayer - 1] == 'E')
		 mlx_destroy_window(data->mlx, data->mlx_wind);
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
		init_map(data, data->map);
	}
	if (data->plant == 0 && data->map[data->yplayer + 1][data->xplayer] == 'E')
		 mlx_destroy_window(data->mlx, data->mlx_wind);
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
		init_map(data, data->map);
	}
	if (data->plant == 0 && data->map[data->yplayer][data->xplayer + 1] == 'E')
		 mlx_destroy_window(data->mlx, data->mlx_wind);
}

// int	handle_input(int keysym, t_data *data, char **map)
// {
// 	if (keysym == 53)
// 		mlx_destroy_window(data->mlx, data->mlx_wind);
// 	if (keysym == 13)
// 		move_up
// 	if (keysym == 0)
// 		move_left
// 	if (keysym == 1)
// 		move_down
// 	if (keysym == 2)
// 		move_right
// 	return (0);
// }