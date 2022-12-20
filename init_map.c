/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:26:27 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/20 14:22:13 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void create_img(t_data *data, char a, int x, int y)
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

int init_map(t_data *data, char  **map)
{
	int x;
	int y;
	
	y = 0;
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
return 0;	
}