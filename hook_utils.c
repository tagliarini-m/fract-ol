/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:03:52 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/10/23 00:18:15 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_lock(t_fractol *data)
{
	if (data->lock_julia == 1)
	{
		mlx_string_put(data->mlx, data->mlx_win, 25, 50, RED, "movement:off");
		mlx_string_put(data->mlx, data->mlx_win, 25, 38, WHITE, "Press L");
	}
	if (data->lock_julia == -1)
	{
		mlx_string_put(data->mlx, data->mlx_win, 25, 50, GREEN, "movement:on");
		mlx_string_put(data->mlx, data->mlx_win, 25, 38, WHITE, "Press L");
	}
}

int	julia_motion(int x, int y, t_fractol *data)
{
	if (data->lock_julia == -1)
	{
		data->julia_re = data->shift_x + (x - WIDTH / 2.0)
			* ((4.0 / data->zoom) / WIDTH);
		data->julia_im = data->shift_y - (y - HEIGHT / 2.0)
			* ((4.0 / data->zoom) / HEIGHT);
		data->redraw = 1;
	}
	if (data->redraw == 1)
		redraw(data);
	return (0);
}

int	redraw(t_fractol *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	if (!ft_strncmp(data->name, "mandelbrot", 11))
		draw_mandelbrot(data, -1, -1);
	if (!ft_strncmp(data->name, "julia", 6))
	{
		draw_julia(data, -1, -1);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	julia_lock(data);
	data->redraw = 0;
	return (0);
}
