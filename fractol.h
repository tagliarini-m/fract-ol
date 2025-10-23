/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:41:52 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/10/23 00:20:38 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define MIN_X -2
# define MAX_X 2
# define MIN_Y 2
# define MAX_Y -2

# define WHITE 0xffffffff
# define RED 0xffff0000
# define GREEN 0xff00ff00
# define BLACK 0x000000

# define ESC 65307
# define SCROLL_UP 0x810
# define SCROLL_DW 0x1010
# define UP_KEY 0xff52
# define DW_KEY 0xff54
# define LT_KEY 0xff51
# define RT_KEY 0xff53
# define L_KEY 0x6c

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	double		zoom;
	double		shift_x;
	double		shift_y;
	int			redraw;
	char		*name;
	double		julia_re;
	double		julia_im;
	int			lock_julia;
	t_complex	z;
}			t_fractol;

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
int		argv_validation(int argc, char **argv, t_fractol *data);
void	window_init(t_fractol *data);

int		key_handle(int keycode, t_fractol *data);
int		close_window_button(t_fractol *data);
int		zoom_handle(int button, int x, int y, t_fractol *data);
int		julia_motion(int x, int y, t_fractol *data);

void	draw_mandelbrot(t_fractol *data, int x, int y);
void	draw_julia(t_fractol *data, int x, int y);

int		redraw(t_fractol *data);
int		ft_strncmp(const char *str1, const char *str2, size_t count);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	julia_lock(t_fractol *data);
int		julia_motion(int x, int y, t_fractol *data);
int		key_handle(int keycode, t_fractol *data);

#endif
