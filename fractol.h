/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:51:37 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/29 22:16:14 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifdef __APPLE__
#  define ESC_KEY 53
#  define PLUS_KEY 24
#  define MINUS_KEY 27
#  define MOUSE_SCROLL_UP 4
#  define MOUSE_SCROLL_DOWN 5
#  define MOUSE_LEFT_CLICK 1
#  include "minilibx_macos_opengl/minilibx_opengl_20191021/mlx.h"
# else
#  define ESC_KEY 65307
#  define PLUS_KEY 61
#  define MINUS_KEY 45
#  define MOUSE_SCROLL_UP 4
#  define MOUSE_SCROLL_DOWN 5
#  define MOUSE_LEFT_CLICK 1
#  include "minilibx-linux/mlx.h"
# endif

# include "libftprintf/ft_printf.h"
# include "libftprintf/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_pixel
{
	int			x;
	int			y;
}				t_pixel;

typedef struct s_format
{
	int			nm_sign;
	int			nm_digits;
	int			dot;
	int			e;
	int			e_digits;
	int			e_sign;
}				t_format;

typedef struct s_colors
{
	int			r[3];
	int			g[3];
	int			b[3];
}				t_colors;

typedef struct s_param
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_mem;
	double		zoom;
	double		x_start;
	double		y_start;
	double		upp;
	double		base_upp;
	int			width;
	int			hight;
	int			mandel;
	int			redraw;
	int			mouse_x;
	int			mouse_y;
	int			bpp;
	int			line_size;
	int			endian;
	int			col_tab[512];
	t_complex	c;
}				t_param;

void			init_colors_table(int *col_tab, int endian, const double scale);
double			iterate_julia(t_complex c, t_complex z, int max_iter);
double			iterate_mandel(t_complex c, int max_iter);
void			hook_all_events(t_param *param);
int				render_fractal(t_param *p);
void			set_colors(t_param *p, int mandel, char *row, int width);
void			valid_input(char *x, char *y, t_format *form_x,
					t_format *form_y);
double			parse_input(char *nm, t_format *form, int nm_len);

#endif