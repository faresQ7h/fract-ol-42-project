/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 02:29:50 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/28 23:42:40 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_center_range(t_param *p)
{
	// double old_upp;
	double mx;
	double my;

	if (p->mouse_x == -1 && p->mouse_y == -1)
		return ;
	// old_upp = p->upp;
	p->upp = p->base_upp * p->zoom;
	mx = -(p->mouse_x * p->upp);
	my = p->mouse_y * p->upp;
	p->x_start = mx;
	p->y_start = my;
}

void	init_new_img(t_param *p)
{
	p->img = mlx_new_image(p->mlx, p->width, p->hight);
	p->img_mem = mlx_get_data_addr(p->img, &p->bpp, &p->line_size, &p->endian);
	p->bpp /= 8;
}

int	render_fractal(t_param *p)
{
	if (!p->redraw)
		return (0);
	if (!p->img)
		init_new_img(p);
	set_center_range(p);
	set_colors(p, p->mandel, p->endian, p->img_mem);
	p->redraw = 0;
	return (1);
}
