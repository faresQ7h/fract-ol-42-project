/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 03:16:00 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/28 23:17:15 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_param *param)
{
	mlx_destroy_window(param->mlx, param->win);
	// mlx_destroy_imge later
	exit(0);
	return (0);
}

int	handel_mouse(int button, int x, int y, t_param *param)
{
	if (button == MOUSE_SCROLL_UP)
	{
		param->redraw = 1;
		param->zoom /= 1.04;
		param->mouse_x = x;
		param->mouse_y = y;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		param->redraw = 1;
		param->zoom *= 1.04;
		param->mouse_x = x;
		param->mouse_y = y;
	}
	// Later:
	// Left click to re-center the view
	// Right click to reset zoom
	return (0);
}

int	handel_key(int keycode, t_param *param)
{
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode == PLUS_KEY)
	{
		param->zoom /= 1.1;
		param->redraw = 1;
	}
	else if (keycode == MINUS_KEY)
	{
		param->zoom *= 1.1;
		param->redraw = 1;
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
