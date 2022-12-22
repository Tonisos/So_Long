/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:06:50 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/22 11:37:26 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_wall(t_data *data, int x, int y)
{
	int		img_width;
	int		img_height;	
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, "sprites/wall.xpm",
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->mlx_wind, img, 64 * x, 64 * y);
}

void	create_floor(t_data *data, int x, int y)
{
	int		img_width;
	int		img_height;	
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, "sprites/floor.xpm",
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->mlx_wind, img, 64 * x, 64 * y);
}

void	create_plant(t_data *data, int x, int y)
{
	int		img_width;
	int		img_height;	
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, "sprites/plant.xpm",
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->mlx_wind, img, 64 * x, 64 * y);
}

void	create_door(t_data *data, int x, int y)
{
	int		img_width;
	int		img_height;	
	void	*img;

	if (data->plant == 0)
		img = mlx_xpm_file_to_image(data->mlx, "sprites/dooropen.xpm",
				&img_width, &img_height);
	else
		img = mlx_xpm_file_to_image(data->mlx, "sprites/door.xpm",
				&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->mlx_wind, img, 64 * x, 64 * y);
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
