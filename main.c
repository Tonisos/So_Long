/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:50:32 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/19 16:06:45 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_pix_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	
}
int render_rect(t_data *data, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			data_pix_put(data, j++, i, rect.color);
		++i;
	}
	return (0);
}

// void	render_background(t_data *data, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < WIN_H)
// 	{
// 		j = 0;
// 		while (j < WIN_W)
// 		{
// 			data_pix_put(data, j++, i, color);
// 		}
// 		++i;
// 	}
// }

int	handle_input(int keysym, t_data *data)
{
	if (keysym == 53)
		mlx_destroy_window(data->mlx, data->mlx_wind);
	return (0);
}


int	main(int argc, char **argv)
{
	
	t_data	data;
	// int i;
	// int j;

	// j = 0;
	// i = 0;
	argc = 0;
	get_map(argv);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.mlx_wind = mlx_new_window(data.mlx, 1920, 1080, "My first window!");
	data.img = mlx_new_image(data.mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	
	
	

	// data_pix_put(&data, 500, 500, 0x00FF0000);
	// render_rect(data.data, (t_rect){1920/2, 1080/2, 1000, 800, 0x00FF0000});
	int	i;
	int j;

	i = 1080/2;
	while (i < (1080/2) + 40)
	{
		j = 1920/2;
		while (j < (1920/2) + 30)
			data_pix_put(&data, j++, i, 0x00FF0000);
		++i;
	}

	mlx_put_image_to_window(data.mlx, data.mlx_wind, data.img, 0, 0);
	
	mlx_key_hook(data.mlx_wind, &handle_input, &data);
	// mlx_loop(data.mlx);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}
