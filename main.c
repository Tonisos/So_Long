/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:50:32 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/22 13:24:34 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_message(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

static int	check_arg(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 0;
	if (argc != 2)
		return (display_message("Error\nYou need one and only one file"));
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		return (display_message("Error\nCannot open this file"));
	}
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e'
		|| argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
		return (display_message("Error\nThis is not a .ber file"));
	return (1);
}

static int	handle_input(int keysym, t_data *data)
{
	if (keysym == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_wind);
		exit(0);
	}
	if (keysym == 13)
		move_up(data);
	if (keysym == 0)
		move_left(data);
	if (keysym == 1)
		move_down(data);
	if (keysym == 2)
		move_right(data);
	return (0);
}

int	exit_game(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] && data->testmap[i])
	{	
		free (data->map[i]);
		free (data->testmap[i]);
		i++;
	}
	if (data->map)
		free (data->map);
	if (data->testmap)
		free (data->testmap);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.nbrmouvement = 0;
	if (!check_arg(argc, argv))
		return (0);
	data.map = get_map(argv, &data);
	if (data.map == NULL)
		exit_game(&data);
	data.testmap = get_map(argv, &data);
	if (!check_error_map(&data))
		exit_game(&data);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		exit_game(&data);
	data.mlx_wind = mlx_new_window(data.mlx, data.width * 64, data.height * 64,
			"THE GAME !");
	init_map(&data, data.map);
	mlx_hook(data.mlx_wind, 17, 1L << 2, exit_game, &data);
	mlx_key_hook(data.mlx_wind, &handle_input, &data);
	mlx_loop(data.mlx);
	exit_game(&data);
	return (0);
}
