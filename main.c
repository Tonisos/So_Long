/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:50:32 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/21 18:22:18 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int display_message(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	write(1, "\n", 1);	
	return (0);
}

int check_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (display_message("You need one and only one file"));
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e'
		|| argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
		return (display_message("This is not a .ber file"));

	return (1);
}


int	handle_input(int keysym, t_data *data)
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
	int i;

	i = -1;	
	while(data->map[++i] && data->testmap[i])
	{	
		free (data->map[i]);
		free (data->testmap[i]);
	}
	free (data->map);
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
	data.testmap = get_map(argv, &data);
	int i = 0;
	if (!check_error_map(&data))
		exit_game(&data);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		exit_game(&data);
	data.mlx_wind = mlx_new_window(data.mlx, data.width * 64, data.height * 64, "My first window!");
	init_map(&data, data.map);
	mlx_hook(data.mlx_wind, 17, 1L << 2, exit_game, &data);
	mlx_key_hook(data.mlx_wind, &handle_input, &data);
	mlx_loop(data.mlx);
	return (0);
}
