/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:54:23 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/10/22 23:59:05 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_validation(t_fractol *data)
{
	data->name = "mandelbrot";
	window_init(data);
	draw_mandelbrot(data, -1, -1);
}

void	julia_validation(t_fractol *data, int argc, char **argv)
{
	data->name = "julia";
	window_init(data);
	draw_julia(data, 0, 0);
	if (argc == 2)
	{
		data->name = "julia";
		data->julia_re = 0.285;
		data->julia_im = 0.01;
		window_init(data);
		draw_julia(data, 0, 0);
		return ;
	}
	if (argc == 4)
	{
		data->name = "julia";
		data->julia_re = ft_atof(argv[2]);
		data->julia_im = ft_atof(argv[3]);
		window_init(data);
		draw_julia(data, 0, 0);
		return ;
	}
}

int	argv_validation(int argc, char **argv, t_fractol *data)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		mandelbrot_validation(data);
	else if ((argc == 2 || argc == 4) && !ft_strncmp(argv[1], "julia", 6))
	{
		julia_validation(data, argc, argv);
	}
	else
	{
		ft_putstr_fd("ERROR\n enter one of the options:\n", 1);
		ft_putstr_fd("\t./fractol mandelbrot\n", 1);
		ft_putstr_fd("\t./fractol julia \"x\" \"y\"\n", 1);
		return (1);
	}
	return (0);
}
