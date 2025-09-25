/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 04:50:08 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/25 18:02:46 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	iterate_mandel(t_complex c, double zoom)
{
	int			iter;
	int			max_iter;
	double		temp;
    double      r2;
	t_complex	z;

	iter = 0;
    max_iter = 40 + 25 / zoom;
	z.x = 0;
	z.y = 0;
	while ((z.x * z.x + z.y * z.y) <= 4.0 && iter < max_iter)
	{
		iter++;
		temp = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2.0 * temp * z.y + c.y;
	}
    if(iter == max_iter)
        return(0);
    r2 = z.x*z.x + z.y*z.y;
    if (r2 < 1e-300) 
        r2 = 1e-300;
	return (1.0 - (iter + 1.0 - log(log(r2) / 2.0) / log(2.0)) / (double)max_iter);
}

double	iterate_julia(t_complex c, t_complex z, double zoom)
{
	int		iter;
	int		max_iter;
	double	temp;
    double  r2;

	iter = 0;
	max_iter = 40 + 25 / zoom;
	while ((z.x * z.x + z.y * z.y) <= 4.0 && iter < max_iter)
	{
		iter++;
		temp = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2.0 * temp * z.y + c.y;
	}
    if(iter == max_iter)
        return(0);
    r2 = z.x*z.x + z.y*z.y;
	if (r2 < 1e-300) 
        r2 = 1e-300;
	return (1.0 - (iter + 1.0 - log(log(r2) / 2.0) / log(2.0)) / (double)max_iter);
}

int which_color(double t, int endian, int r[4], int g[4])
{
    int rr;
    int bb;
    int gg;
    int low;
    int b[4];

    b[0] = 0x00;
    b[1] = 0xFF;
    b[2] = 0xD1;
    b[3] = 0x00;
    low = floor(t * 3);
    rr = r[low] + (r[(int)ceil(t * 3)] * t);
    bb = b[low] + (b[(int)ceil(t * 3)] * t);
    gg = g[low] + (g[(int)ceil(t * 3)] * t);
    if (!endian)
        return(bb << 16 | gg << 8 | rr);
    return(rr << 16 | gg << 8 | bb);
}

int	color(t_param *p, t_complex nm, int mandel, int endian)
{
	double	t;
    int r[4];
    int g[4];

    r[0] = 0x00;
    r[1] = 0x00;
    r[2] = 0xB3;
    r[3] = 0xFF;
    g[0] = 0x00;
    g[1] = 0x00;
    g[2] = 0x03;
    g[3] = 0x24;
	if (mandel)
		t = iterate_mandel(nm, p->zoom);
	else
		t = iterate_julia(p->c, nm, p->zoom);

    return(which_color(t, endian, r, g));
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
            nm.x -= upp;
        }
        i++;
        nm.y -= upp;
    }
    mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
