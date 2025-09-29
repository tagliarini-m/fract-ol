/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:41:52 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/09/29 20:51:36 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>


# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 50
# define MIN_X -2
# define MAX_X 2
# define MIN_Y 2
# define MAX_Y -2

# define SCROLL_UP 0x810
# define SCROLL_DW 0x1010
# define O_KEY 0x6f
# define P_KEY 0x70


typedef struct s_fractol
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	double	shift_x;
	double	shift_y;
	int		redraw;

}			t_fractol;

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;


int		key_handle(int keycode, t_fractol *data);
int		close_window_button(t_fractol *data);
void	draw_mandelbrot(t_fractol *data, int x, int y);
int		zoom_handle(int button, int x, int y, t_fractol *data);






#endif
