/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:05:42 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/22 11:37:54 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_height(char **argv, int i)
{
	int		height;
	int		fd;
	char	*lign;

	height = 0;
	fd = open(argv[1], O_RDONLY);
	lign = get_next_line(fd);
	if (lign)
	{
		height++;
	}
	free(lign);
	while (i != 0)
	{
		lign = get_next_line(fd);
		if (!lign)
			i = 0;
		free(lign);
		height ++;
	}
	height --;
	close (fd);
	return (height);
}

int	check_rec(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != data->width)
			return (display_message("the map isn't a rectangle"));
		i++;
	}
	return (1);
}

static int	get_width(char **argv)
{
	int		width;
	int		fd;
	char	*lign;

	width = 0;
	fd = open(argv[1], O_RDONLY);
	lign = get_next_line(fd);
	while (lign[width])
		width ++;
	free (lign);
	while (lign)
	{
		lign = get_next_line(fd);
		free (lign);
	}
	close(fd);
	return (--width);
}

char	**get_map(char **argv, t_data *data)
{
	int		fd;
	char	**map;
	char	*lign;
	int		i;

	i = 0;
	data->height = get_height(argv, 1);
	data->width = get_width(argv);
	if (data->width == 0)
		return (NULL);
	map = malloc (sizeof(char *) * (data->height));
	fd = open(argv[1], O_RDONLY);
	while (i < data->height)
	{
		map[i] = get_next_line(fd);
		if (map[i][data->width] == '\n')
			map[i][data->width] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}
