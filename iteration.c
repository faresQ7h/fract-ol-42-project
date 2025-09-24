/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:42:23 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/23 17:44:02 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int is_in_set(t_complex nm, int mandel)
{
    t_complex z;
    t_complex c;

    if (mandel == 1)
    {
        z.x = 0;
        z.y = 0;
        c.x = nm.x;
        c.y = nm.y;
    }
    else
    {
        
    }
}