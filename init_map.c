/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:26:27 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/22 14:46:27 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_img(t_data *data)
{
	int		img_width;
	int		img_height;	

	data->imgwall = mlx_xpm_file_to_image(data->mlx, "sprites/wall.xpm",
			&img_width, &img_height);
	data->imgfloor = mlx_xpm_file_to_image(data->mlx, "sprites/floor.xpm",
			&img_width, &img_height);
	data->imgplant = mlx_xpm_file_to_image(data->mlx, "sprites/plant.xpm",
			&img_width, &img_height);
	data->imgdooropen = mlx_xpm_file_to_image(data->mlx, "sprites/dooropen.xpm",
			&img_width, &img_height);
	data->imgdoor = mlx_xpm_file_to_image(data->mlx, "sprites/door.xpm",
			&img_width, &img_height);
}

static void	create_img(t_data *data, char a, int x, int y)
{
	if (a == 'P')
		create_player(data, x, y);
	if (a == 'E')
		create_door(data, x, y);
	if (a == '1')
		create_wall(data, x, y);
	if (a == 'C')
		create_plant(data, x, y);
	if (a == '0')
		create_floor(data, x, y);
}

static char	*simple_itoa(t_data *data)
{
	char	*str;
	long	i;
	long	nbr;

	nbr = data->nbrmouvement;
	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i ++;
	}
	nbr = data->nbrmouvement;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[i--] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}

int	init_map(t_data *data, char **map)
{
	int		x;
	int		y;
	char	*str;

	y = 0;
	mlx_clear_window(data->mlx, data->mlx_wind);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			create_img(data, map[y][x], x, y);
			x++;
		}
		y++;
	}
	display_message("number of mouvement : ");
	str = simple_itoa(data);
	display_message(str);
	free (str);
	return (0);
}
