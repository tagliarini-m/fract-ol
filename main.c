/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:26:38 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/10/22 23:57:46 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	window_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 800, 800, "mandelbrot");
	data->img = mlx_new_image(data->mlx, 800, 800);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	data->zoom = 1.0;
	data->shift_x = 0.0;
	data->shift_y = 0.0;
}

int	main(int argc, char **argv)
{
	t_fractol	data;

	if (argv_validation(argc, argv, &data) == 1)
		return (1);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	if (!ft_strncmp(argv[1], "julia", 6))
	{
		mlx_string_put(data.mlx, data.mlx_win, 25, 38, 0xffffffff, "Press L");
		data.lock_julia = 1;
	}
	mlx_key_hook(data.mlx_win, &key_handle, &data);
	mlx_mouse_hook(data.mlx_win, zoom_handle, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window_button, &data);
	mlx_hook(data.mlx_win, 6, 1L << 6, julia_motion, &data);
	mlx_loop(data.mlx);
	return (0);
}
