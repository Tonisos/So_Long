/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:06:50 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/22 14:45:07 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_wall(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_wind,
		data->imgwall, 64 * x, 64 * y);
}

void	create_floor(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_wind,
		data->imgfloor, 64 * x, 64 * y);
}

void	create_plant(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_wind,
		data->imgplant, 64 * x, 64 * y);
}

void	create_door(t_data *data, int x, int y)
{
	if (data->plant == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_wind,
			data->imgdooropen, 64 * x, 64 * y);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_wind,
			data->imgdoor, 64 * x, 64 * y);
}

void	create_player(t_data *data, int x, int y)
{
	int		img_width;
	int		img_height;	

	data->xplayer = x;
	data->yplayer = y;
	data->xtestmap = x;
	data->ytestmap = y;
	data->imgplayer = mlx_xpm_file_to_image(data->mlx, "sprites/player.xpm",
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->mlx_wind,
		data->imgplayer, 64 * x, 64 * y);
}
