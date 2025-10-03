/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:26:38 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/10/02 21:33:42 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

int	get_color_bg(int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / MAX_ITER;
	// r = (int)(25 * (1 - t) * t * t * t * 256);
	r = 0;
	g = (int)(10 * (1 - t) * (1 - t) * t * t * 256);
	b = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 256);
	return ((r << 16) | (b << 8) | g);
}



int	calculate_mandelbrot(t_complex z, t_complex c, int iter)
{
	double	xtemp;
	while (z.re*z.re + z.im * z.im <= 4.0 && iter < MAX_ITER)
	{
		xtemp = z.re * z.re - z.im*z.im + c.re;
		z.im = 2*z.re * z.im + c.im;
		z.re = xtemp;
		iter++;
	}
	return (iter);
}

void	draw_julia(t_fractol *data, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			iter;
	int			color;

	z.re = x;
	z.im = y;
	// y = -1;
	while (++y < HEIGHT)
	{
		c.im = -(y - HEIGHT/2) * (4.0 / data->zoom) / HEIGHT + data->shift_y;
		// x = -1;
		while (++x < WIDTH)
		{
			c.re = (x - WIDTH/2) * (4.0 / data->zoom) /  WIDTH + data->shift_x;
			iter = calculate_mandelbrot(z, c, 0);
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
		c.im = -(y - HEIGHT/2) * (4.0 / data->zoom) / HEIGHT + data->shift_y;
		x = -1;
		while (++x < WIDTH)
		{
			c.re = (x - WIDTH/2) * (4.0 / data->zoom) /  WIDTH + data->shift_x;
			iter = calculate_mandelbrot(z, c, 0);
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

void	window_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 800, 800, "mandelbrot");
	data->img = mlx_new_image(data->mlx, 800, 800);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
	data->zoom = 1.0;
	data->shift_x = 0.0;
	data->shift_y = 0.0;
}

int	argv_validation(int argc, char **argv, t_fractol *data)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
	{
		data->name = "mandelbrot";
		window_init(data);
		draw_mandelbrot(data, -1, -1);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "julia", 6))
	{
		data->name = "julia";
		window_init(data);
		draw_julia(data, -1, -1);
	}
	else
	{
		ft_putstr_fd("ERROR\n enter one of the options:\n \t./fractol mandelbrot\n \t./fractol julia", 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	data;

	if (argv_validation(argc, argv, &data) == 1)
		return (1);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_key_hook(data.mlx_win, &key_handle, &data);
	mlx_mouse_hook(data.mlx_win, zoom_handle, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window_button, &data);

	mlx_loop(data.mlx);

	return 0;
}
