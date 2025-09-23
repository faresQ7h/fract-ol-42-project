/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 02:29:50 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/23 05:31:30 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel set_center_range(t_param *p)
{
    t_pixel center;

    if (p->mouse_x == -1 && p->mouse_y == -1)
    {
        center.x = p->width / 2;
        center.y = p->hight / 2;
        return (center);
    }
    center.x = p->mouse_x;
    center.y = p->mouse_y;
    p->upp = (p->x_len/(double)p->width) * p->zoom;
    p->x_start = center.x * p->upp;
    p->y_start = center.y * p->upp;
    return (center);
}

void    init_new_img(t_param *p)
{
    p->img = mlx_new_image(p->mlx, p->width, p->hight);
    p->img_mem = mlx_get_data_addr(p->img, &p->bpp, &p->line_size, &p->endian); // i can creat a struc special for img later 
    p->bpp /= 8;
}

int	render_fractal(t_param *p)
{
    t_pixel center;

    if(!p->redraw)
        return(0); // 0 = not drawing, 1 = drawed sucessfully
    if (!p->img)
        init_new_img(p);
    center = set_center_range(p);
    set_colors(p, p->mandel, p->endian, p->img_mem);
    p->redraw = 0;
    return(1);
}
