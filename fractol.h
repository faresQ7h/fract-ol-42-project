/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:51:37 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/22 04:43:33 by farmoham         ###   ########.fr       */
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
#  define MOUSE_RIGHT_CLICK 2
#  define MOUSE_MIDDLE_CLICK 3
#  include "minilibx_macos_opengl/minilibx_opengl_20191021/mlx.h"
# else
#  define ESC_KEY 65307
#  define PLUS_KEY 61
#  define MINUS_KEY 45
#  define MOUSE_SCROLL_UP 4
#  define MOUSE_SCROLL_DOWN 5
#  define MOUSE_LEFT_CLICK 1
#  define MOUSE_RIGHT_CLICK 3
#  define MOUSE_MIDDLE_CLICK 2
#  include "minilibx-linux/mlx.h"
# endif

# include "libftprintf/ft_printf.h"
# include "libftprintf/libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_complex
{
	int		x;
	int		yi;
}			t_complex;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_mem;
	double	zoom;
	int		mandel;
	int		redraw;
}			t_param;

void		hook_all_events(t_param *param);

#endif