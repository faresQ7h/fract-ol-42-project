/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 03:16:00 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/29 23:59:45 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_window(t_param *p)
{
	mlx_destroy_image(p->mlx, p->img);
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
	return (0);
}

static int	handel_mouse(int button, int x, int y, t_param *p)
{
	if (button == MOUSE_SCROLL_UP)
	{
		p->zoom /= 1.04;
		p->mouse_x = x;
		p->mouse_y = y;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		p->zoom *= 1.04;
		p->mouse_x = x;
		p->mouse_y = y;
	}
	else if (button == MOUSE_LEFT_CLICK)
	{
		p->zoom = 1;
		p->mouse_x = -1;
		p->mouse_y = -1;
		p->upp = p->base_upp;
		p->x_start = -3;
		p->y_start = (((921.0 * 6.0) / 821.0) / 2.0);
	}
	p->redraw = 1;
	return (0);
}

static int	handel_key(int keycode, t_param *p)
{
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode == PLUS_KEY)
	{
		p->zoom /= 1.04;
		p->redraw = 1;
	}
	else if (keycode == MINUS_KEY)
	{
		p->zoom *= 1.04;
		p->redraw = 1;
	}
	return (0);
}

void	hook_all_events(t_param *param)
{
	mlx_hook(param->win, 17, 0, close_window, param);
	mlx_key_hook(param->win, handel_key, param);
	mlx_mouse_hook(param->win, handel_mouse, param);
	mlx_loop_hook(param->mlx, render_fractal, param);
}
