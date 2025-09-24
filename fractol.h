/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:41:52 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/09/23 20:14:20 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 500
# define MIN_X -2
# define MAX_X 2
# define MIN_Y 2
# define MAX_Y -2

typedef struct s_fractol
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

}			t_fractol;

int	close_window_esc(int keycode, t_fractol *data);
int	close_window_button(t_fractol *data);


#endif
