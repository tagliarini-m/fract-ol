/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:43:48 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/10/23 00:30:51 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color_bg(int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / (double)MAX_ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	if (r < 0)
		r = 0;
	else if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	else if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	else if (b > 255)
		b = 255;
	return ((r << 16) | (b << 8) | g);
}

int	calculate_fractal(t_complex z, t_complex c, int iter)
{
	double	xtemp;

	while (z.re * z.re + z.im * z.im <= 4.0 && iter < MAX_ITER)
	{
		xtemp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = xtemp;
		iter++;
	}
	return (iter);
}

t_complex	set_julia(t_fractol *data)
{
	t_complex	c;

	c.re = data->julia_re;
	c.im = data->julia_im;
	return (c);
}

void	draw_julia(t_fractol *data, int x, int y)
{
	t_complex	c;
	int			iter;
	int			color;

	c = set_julia(data);
	y = 0;
	while (y++ < HEIGHT)
	{
		data->z.im = - (y - HEIGHT / 2) * (4.0 / data->zoom)
			/ HEIGHT + data->shift_y;
		x = 0;
		while (x++ < WIDTH)
		{
			data->z.re = (x - WIDTH / 2) * (4.0 / data->zoom)
				/ WIDTH + data->shift_x;
			iter = calculate_fractal(data->z, c, 0);
			if (iter >= MAX_ITER)
				my_mlx_pixel_put(data, x, y, BLACK);
			else
			{
				color = get_color_bg(iter);
				my_mlx_pixel_put(data, x, y, color);
			}
		}
	}
}

void	draw_mandelbrot(t_fractol *data, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			iter;
	int			color;

	z.re = 0.0;
	z.im = 0.0;
	y = -1;
	while (++y < HEIGHT)
	{
		c.im = -(y - HEIGHT / 2) * (4.0 / data->zoom) / HEIGHT + data->shift_y;
		x = -1;
		while (++x < WIDTH)
		{
			c.re = (x - WIDTH / 2) * (4.0 / data->zoom) / WIDTH + data->shift_x;
			iter = calculate_fractal(z, c, 0);
			if (iter >= MAX_ITER)
				my_mlx_pixel_put(data, x, y, 0x000000);
			else
			{
				color = get_color_bg(iter);
				my_mlx_pixel_put(data, x, y, color);
			}
		}
	}
}
