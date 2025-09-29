/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 04:50:08 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/30 01:24:32 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//green
// colors->r[0] = 0x00;
// colors->r[1] = 0x39;
// colors->r[2] = 0x6A;
// colors->g[0] = 0x12;
// colors->g[1] = 0xFF;
// colors->g[2] = 0x0D;
// colors->b[0] = 0x0F;
// colors->b[1] = 0x14;
// colors->b[2] = 0xAD;
//megma
// colors->r[0] = 0x0A;
// colors->r[1] = 0xB3;
// colors->r[2] = 0xFF;
// colors->g[0] = 0x00;
// colors->g[1] = 0x00;
// colors->g[2] = 0xD1;
// colors->b[0] = 0x10;
// colors->b[1] = 0x8F;
// colors->b[2] = 0x66;
//gry
// colors->r[0] = 0x00;
// colors->r[1] = 0x77;
// colors->r[2] = 0xFF;
// colors->g[0] = 0x00;
// colors->g[1] = 0x77;
// colors->g[2] = 0xFF;
// colors->b[0] = 0x00;
// colors->b[1] = 0x77;
// colors->b[2] = 0xFF;
//best
// colors->r[0] = 0x00;
// colors->r[1] = 0x3A; 
// colors->r[2] = 0xE6;
// colors->g[0] = 0x12;
// colors->g[1] = 0xA6;
// colors->g[2] = 0xE6;
// colors->b[0] = 0x0F;
// colors->b[1] = 0x5C;
// colors->b[2] = 0xE6;
//gold
//colors->r[0] = 0x0A;
//colors->r[1] = 0x2B;
//colors->r[2] = 0xE0;
//colors->g[0] = 0x24;
//colors->g[1] = 0xB3;
//colors->g[2] = 0xF7;
//colors->b[0] = 0x72;
//colors->b[1] = 0xFF;
//colors->b[2] = 0xFF;

static void	init_colors(t_colors *colors)
{
	colors->r[0] = 0x00;
	colors->r[1] = 0x3A;
	colors->r[2] = 0xD8;
	colors->g[0] = 0x12;
	colors->g[1] = 0xB0;
	colors->g[2] = 0xD8;
	colors->b[0] = 0x0F;
	colors->b[1] = 0x5C;
	colors->b[2] = 0xD8;
}

static int	make_color(t_colors *c, int seg, double f, int endian)
{
	if (endian)
	{
		return (((c->r[seg] + (int)((c->r[seg + 1] - c->r[seg]) * f)) << 16)
			| ((c->g[seg] + (int)((c->g[seg + 1] - c->g[seg]) * f)) << 8)
			| ((c->b[seg] + (int)((c->b[seg + 1] - c->b[seg]) * f))));
	}
	else
	{
		return (((c->b[seg] + (int)((c->b[seg + 1] - c->b[seg]) * f)) << 16)
			| ((c->g[seg] + (int)((c->g[seg + 1] - c->g[seg]) * f)) << 8)
			| ((c->r[seg] + (int)((c->r[seg + 1] - c->r[seg]) * f))));
	}
}

void	init_colors_table(int *col_tab, int endian, const double scale)
{
	int			seg;
	int			i;
	double		f;
	double		u;
	t_colors	c;

	init_colors(&c);
	i = 0;
	while (i < 512)
	{
		u = i * scale;
		seg = (int)u;
		f = u - seg;
		if (seg >= 2)
		{
			seg = 1;
			f = 1.0;
		}
		col_tab[i] = make_color(&c, seg, f, endian);
		i++;
	}
}

static int	color(t_param *p, t_complex nm, int mandel, int max_iter)
{
	double	t;

	if (mandel)
		t = iterate_mandel(nm, max_iter);
	else
		t = iterate_julia(p->c, nm, max_iter);
	if (t <= 0)
	{
		if (p->endian != 0)
			return (0x040000);
		return (0x000004);
	}
	t = 1.0 - (t / (double)max_iter);
	if (t > 1)
		t = 1;
	return (p->col_tab[(int)(t * 511 + 0.5)]);
}

void	set_colors(t_param *p, int mandel, char *row, int max_iter)
{
	int			i;
	int			j;
	int			width;
	double		upp;
	t_complex	nm;

	i = 0;
	upp = p->upp;
	width = p->width;
	nm.y = p->y_start;
	while (i < p->hight)
	{
		row = p->img_mem + i * p->line_size;
		j = 0;
		nm.x = p->x_start;
		while (j < width)
		{
			*(((int *)row) + j) = color(p, nm, mandel, max_iter);
			j++;
			nm.x += upp;
		}
		i++;
		nm.y -= upp;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
