/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:02:59 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/09/24 20:17:21 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window_esc(int keycode, t_fractol *data)
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

// int	zoom_handle(int keycode)
// {
// 	if (button == 4)
// 	{
// 		cx *= 1.1
// 		cy *= 1.1
// 	}
// }
