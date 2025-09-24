/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 04:50:08 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/23 17:42:36 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int color(t_param *p, t_complex nm, int mandel, int endain)
{
    int iter;
    int r;
    int g;
    int b;

    iter = is_in_set(nm, mandel);
}

void   set_colors(t_param *p, int mandel, int endian, char *row)
{
    int i;
    int j;
    int width;
    double upp;
    t_complex nm;

    (void)mandel;
    (void)endian;
    i = 0;
    width = p->width;
    upp = p->upp;
    nm.y = p->y_start;
    while(i < p->hight)
    {
        j = 0;
        nm.x = p->x_start;
        while(j < width)
        {
            *((int*)row) = color(p, nm, mandel, endian);
            row += 4;
            j++;
            nm.x -= upp;
        }
        i++;
        row = p->img_mem + i * p->line_size;
        nm.y -= upp;
    }
    mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}