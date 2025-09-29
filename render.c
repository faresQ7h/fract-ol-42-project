/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 02:29:50 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/29 22:14:11 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_xy_start(t_param *p)
{
	double	upp_old;
	double	upp_new;

	if (p->mouse_x < 0 || p->mouse_y < 0)
		return ;
	upp_old = p->upp;
	upp_new = p->base_upp * p->zoom;
	p->x_start += p->mouse_x * (upp_old - upp_new);
	p->y_start += p->mouse_y * (upp_new - upp_old);
	p->upp = upp_new;
}

int	render_fractal(t_param *p)
{
	int	max_iter;

	if (!p->redraw)
		return (0);
	set_xy_start(p);
	max_iter = 35 + (25.0 * log2(1.0 / p->upp));
	if (max_iter < 32)
		max_iter = 32;
	if (max_iter > 2000)
		max_iter = 2000;
	set_colors(p, p->mandel, NULL, max_iter);
	p->redraw = 0;
	return (1);
}
