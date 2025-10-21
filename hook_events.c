/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:02:59 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/10/21 20:50:09 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	redraw(t_fractol *data);

void	arrow_keys_handle(int keycode, t_fractol *data)
{
	if (keycode == UP_KEY)
	{
		data->shift_y += 0.2 / data->zoom;
		data->redraw = 1;
	}
	if (keycode == DW_KEY)
	{
		data->shift_y -= 0.2 / data->zoom;
		data->redraw = 1;
	}
	if (keycode == RT_KEY)
	{
		data->shift_x += 0.2 / data->zoom;
		data->redraw = 1;
	}
	if (keycode == LT_KEY)
	{
		data->shift_x -= 0.2 / data->zoom;
		data->redraw = 1;
	}
}

int	key_handle(int keycode, t_fractol *data)
{
	if (keycode == ESC)
	{
		if (data->img)
			mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	arrow_keys_handle(keycode, data);
	if (keycode == L_KEY)
	{
		data->lock_julia *= -1;
		data->redraw = 1;
	}
	if (data->redraw == 1)
		redraw(data);
	return (0);
}

int	close_window_button(t_fractol *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	redraw(t_fractol *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
	if (!ft_strncmp(data->name, "mandelbrot", 11))
		draw_mandelbrot(data, -1, -1);
	if (!ft_strncmp(data->name, "julia", 6))
	{
		draw_julia(data, -1, -1);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);

	if (data->lock_julia == 1)
	{
		mlx_string_put(data->mlx, data->mlx_win, 25, 50, 0xffff0000, "movement:off");
		mlx_string_put(data->mlx, data->mlx_win, 25, 38, 0xffffffff, "Press L");
	}
	if (data->lock_julia == -1)
	{
		mlx_string_put(data->mlx, data->mlx_win, 25, 50, 0xff00ff00, "movement:on");
		mlx_string_put(data->mlx, data->mlx_win, 25, 38, 0xffffffff, "Press L");
	}
	data->redraw = 0;
	return (0);
}

int	zoom_handle(int button, int x, int y, t_fractol *data)
{
	double pos_x;

	double pos_y;
	pos_x = data->shift_x + (x - WIDTH / 2.0) * ((4.0 / data->zoom) / WIDTH);
	pos_y = data->shift_y - (y - HEIGHT / 2.0) * ((4.0 / data->zoom) / HEIGHT);
	if (button == 4)
	{
		data->zoom *= 1.05;
		data->redraw = 1;
	}
	else if (button == 5)
	{
		data->zoom *= 0.9;
		data->redraw = 1;
	}
	else
		return (0);
	data->shift_x = pos_x - (x - WIDTH / 2.0) * ((4.0 / data->zoom) / WIDTH);
	data->shift_y = pos_y + (y - HEIGHT / 2.0) * ((4.0 / data->zoom) / HEIGHT);
	if (data->redraw == 1)
		redraw(data);
	return (0);
}
int	julia_motion(int x, int y, t_fractol *data)
{
	if (data->lock_julia == -1)
	{
		data->julia_re = data->shift_x + (x - WIDTH / 2.0) * ((4.0 / data->zoom) / WIDTH);
		data->julia_im = data->shift_y - (y - HEIGHT / 2.0) * ((4.0 / data->zoom) / HEIGHT);
		data->redraw = 1;
	}
	if (data->redraw == 1)
		redraw(data);
	return (0);
}
