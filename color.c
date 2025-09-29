/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 04:50:08 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/29 04:44:20 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int which_color(double t2, int endian)
{
    int r[3];
    int g[3];
    int b[3];
    int seg;
    double f;

    r[0] = 0x0A;
    r[1] = 0x2B;
    r[2] = 0xE0;
    g[0] = 0x24;
    g[1] = 0xB3;
    g[2] = 0xF7;
    b[0] = 0x72;
    b[1] = 0xFF;
    b[2] = 0xFF;
    seg = (int)t2;
    f = t2 - seg;
    if (seg >= 2)
    {
        seg = 1;
        f = 1.0;
    }
    if (endian)
        return ((r[seg] + (int)((r[seg+1]-r[seg]) * f)) << 16) |
               ((g[seg] + (int)((g[seg+1]-g[seg]) * f)) <<  8) |
               ((b[seg] + (int)((b[seg+1]-b[seg]) * f))      );
    else
        return ((b[seg] + (int)((b[seg+1]-b[seg]) * f)) << 16) |
               ((g[seg] + (int)((g[seg+1]-g[seg]) * f)) <<  8) |
               ((r[seg] + (int)((r[seg+1]-r[seg]) * f))      );
}

int	color(t_param *p, t_complex nm, int mandel, int endian)
{
	double	t;
    double want;
    double zoom;

    zoom = p->zoom;
    if (zoom < 1e-12)
        zoom = 1e-12;
    want = 40.0 + 25.0 / zoom;
    if (want < 1.0)
        want = 1.0;
    if (want > 5000.0)
        want = 5000.0;
    if (mandel)
		t = iterate_mandel(nm, (int)want);
	else
		t = iterate_julia(p->c, nm, (int)want);
    if (t > 1 || t < 0)
        t = MAX(0.0, MIN(1.0, t));
    if(t == 0)
    {
        if (endian != 0)
            return (0x040000);
        else
            return (0x000004);
    }
    t = t * 2.0;
    if (!(t >= 0.0))
        t = 0.0;
    if (t > 2.0)
        t = 2.0;
    return(which_color(t, endian));
}

void    set_colors(t_param *p, int mandel, int endian, char *row)
{
    int         i;
    int         j;
    int         width;
    double      upp;
    t_complex   nm;

    i = 0;
    width = p->width;
    upp = p->upp;
    nm.y = p->y_start;
    while (i < p->hight)
    {
        row = p->img_mem + i * p->line_size;
        j = 0;
        nm.x = p->x_start;
        while (j < width)
        {
            *(((int *)row) + j) = color(p, nm, mandel, endian);
            j++;
            nm.x += upp;
        }
        i++;
        nm.y -= upp;
    }
    mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
