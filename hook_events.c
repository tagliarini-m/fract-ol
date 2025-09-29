/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:02:59 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/09/29 20:26:00 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handle(int keycode, t_fractol *data)
{
	if (keycode == 65307)
	{
		if (data->img)
			mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}

	if (keycode == O_KEY)
	{
		zoom_handle(keycode, 1, 1, data);
	}
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
	draw_mandelbrot(data, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int	zoom_handle(int button, int x, int y, t_fractol *data)
{
	double pos_x;
	double pos_y;
	double zoom_factor;

	data->redraw = 0;
	pos_x = data->shift_x + (x - WIDTH / 2.0) * ((4.0 / data->zoom) / WIDTH);
	pos_y = data->shift_y - (y - HEIGHT / 2.0) * ((4.0 / data->zoom) / HEIGHT);
	if (button == 4)
	{
		data->zoom *= 1.1;
		printf("x = %f\ny = %f\n\n", pos_x, pos_y);
		data->redraw = 1;
	}
	else if (button == 5)
	{
		data->zoom *= 0.9;
		printf("x = %f\ny = %f\n\n", pos_x, pos_y);
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





	// mpy = env->fract->y_offset - (y - env->window->height / 2.0f) * (4.0f
	// 		/ env->fract->zoom) / env->window->height;

	// env->fract->zoom *= zoom;


	// env->fract->y_offset = mpy + (y - env->window->height / 2.0f) * (4.0f
	// 		/ env->fract->zoom) / env->window->height;
	// ft_calc_coordinate(env->fract, env->window, x, y);
