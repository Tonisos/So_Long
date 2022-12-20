/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:50:32 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/20 17:05:40 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	data_pix_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
	
// }
// int render_rect(t_data *data, t_rect rect)
// {
// 	int	i;
// 	int j;

// 	i = rect.y;
// 	while (i < rect.y + rect.height)
// 	{
// 		j = rect.x;
// 		while (j < rect.x + rect.width)
// 			data_pix_put(data, j++, i, rect.color);
// 		++i;
// 	}
// 	return (0);
// }



int	handle_input(int keysym, t_data *data)
{
	if (keysym == 53)
		mlx_destroy_window(data->mlx, data->mlx_wind);
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


int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc != 2)
		return (0);
	
	data.map = get_map(argv, &data);
	if (!check_error_map(&data))
		return (0);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.mlx_wind = mlx_new_window(data.mlx, 1920, 1080, "My first window!");
	// data.img = mlx_xpm_file_to_image(data.mlx, "wall.xpm", &img_width, &img_height);
	// data.img = mlx_new_image(data.mlx, 960, 540);
	// data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	// void *img2 = mlx_xpm_file_to_image(data.mlx, "player.xpm", &img_width, &img_height);

	init_map(&data, data.map);
	// mlx_put_image_to_window(data.mlx, data.mlx_wind, data.img, 64, 64);
	// mlx_put_image_to_window(data.mlx, data.mlx_wind, img2, 0, 0);
	
	mlx_key_hook(data.mlx_wind, &handle_input, &data);
	mlx_loop(data.mlx);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}
