/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:05:42 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/20 17:06:32 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_height(char **argv)
{
	int height;
	int	fd;

	height = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd))
		height ++;
	close (fd);
	return (height);
}
int check_rec(int width, char **argv)
{
	int	i;
	int j;
	char *lign;
	int fd;
	int height;

	height = get_height(argv) - 1;
	
	fd = open(argv[1], O_RDONLY);
	i = 0; 
	while (i < height)
	{
		lign = get_next_line(fd);
		j = 0;
		// printf("%s\n", lign);
		while (lign[j])
			j++;
		free (lign);
		if (j != width)
		{
			close(fd);
			return (1);
		}
		i++;
	}	
	return (0);
	
}

int get_width(char **argv)
{
	int width;
	int	fd;
	char *lign;


	width = 0;
	
	fd = open(argv[1], O_RDONLY);
	lign = get_next_line(fd);
	while (lign[width])
		width ++;
	while (get_next_line(fd))
		;
	free (lign);
	close(fd);
	if (check_rec(width, argv))
		return (0);
	
	return (--width);
}
// int check_close(char **map, char **argv)
// {
// 	int i;
// 	int j;
		
// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if ((i == 0 || i == get_height(argv) - 1) && map[i][j] != '1')
// 				return (1);
// 			if ((j == 0 || j == get_width(argv) - 1) && map[i][j] != '1')
// 				return (1);
// 			j++;
// 		}	
// 		i++;
// 	}
// 	return (0);
// }

char **get_map(char **argv, t_data *data)
{
	int	fd;
	char **map;
	char *lign;
	int	width;
	int	height;
	int	i;

	i = 0;
	data->height = get_height(argv);
	data->width = get_width(argv);
	
	if (data->width == 0)
		return (NULL);
	map = malloc(sizeof(char*) * (data->height));
	fd = open(argv[1], O_RDONLY);
	while(i < data->height)
	{
		map[i] = get_next_line(fd);
		map[i][data->width] = '\0';
		i++;
	}
	map[i] = NULL;

	// printf("%d", check_close(map, argv));
	
	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);


	return (map);
}