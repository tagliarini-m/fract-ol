/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:26:38 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/09/24 21:56:59 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	ft_hex_to_int(char iter)
{
	if (iter >= 0 && iter <= 9)
		return (iter - '0');
	else if (iter >= 'a' && iter <= 'f')
		return (10 + (iter - 'a'));
	else
		return (-1);
}

int		ft_puthex(int iter)
{
	char	*base;
	int		color;

	base = "0123456789abcdef";
	color = 0;
	if (iter >= 16)
		ft_puthex(iter / 16);
	color += ft_hex_to_int(base[iter % 16]);
	return (color);
}

int	get_color_bg(int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / MAX_ITER;
	// r = (int)(9 * (1 - t) * t * t * t * 256);
	r = 0;
	g = (int)(16 * (1 - t) * (1 - t) * t * t * 256);
	b = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 256);
	return ((r << 16) | (b << 8) | g);
}



int	calculate_mandelbrot(t_complex z, t_complex c, int iter)
{
	double	xtemp;
	z.re = 0.0;
	z.im = 0.0;
	while (z.re*z.re + z.im * z.im <= 4.0 && iter < MAX_ITER)
	{
		xtemp = z.re * z.re - z.im*z.im + c.re;
		z.im = 2*z.re * z.im + c.im;
		z.re = xtemp;
		iter++;
	}

	return (iter);
}

void	draw_mandelbrot(t_fractol *data, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			iter;
	int			color;
	while (y < HEIGHT)
	{
		c.im = -2.0 + y * (4.0 / HEIGHT);
		x = 0;
		while (x < WIDTH)
		{
			c.re = -2.0 + x * (4.0 / WIDTH);
			iter = calculate_mandelbrot(z, c, 0);
			if (iter == MAX_ITER)
			my_mlx_pixel_put(data, x, y, 0x000000);
			else
			{
				color = get_color_bg(iter);
				my_mlx_pixel_put(data, x, y, color);
			}
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_fractol	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 800, 800, "mandelbrot");
	data.img = mlx_new_image(data.mlx, 800, 800);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);

	draw_mandelbrot(&data, 0, 0);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_key_hook(data.mlx_win, &close_window_esc, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window_button, &data);

	mlx_loop(data.mlx);

	return 0;
}
