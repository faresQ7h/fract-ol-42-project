/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 02:29:50 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/29 04:27:07 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_xy_start(t_param *p)
{
	double upp_old;
	double upp_new;
//handels zooming in/out and sets unites per unit and x start (min) y start (max)

    if (p->mouse_x < 0 || p->mouse_y < 0)
        return;
    upp_old = p->upp;
    upp_new = p->base_upp * p->zoom;
	p->x_start += p->mouse_x * (upp_old - upp_new);
    p->y_start += p->mouse_y * (upp_new - upp_old);
    p->upp = upp_new;
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
	set_xy_start(p);
	set_colors(p, p->mandel, p->endian, p->img_mem);
	p->redraw = 0;
	return (1);
}
