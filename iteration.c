/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:56:55 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/30 00:47:11 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	in_set(t_complex c)
{
	double	xm;
	double	y2;
	double	q;
	double	xp1;

	xm = c.x - 0.25;
	y2 = c.y * c.y;
	q = xm * xm + y2;
	if (q * (q + xm) <= 0.25 * y2)
		return (1);
	xp1 = c.x + 1.0;
	if (xp1 * xp1 + y2 <= 0.0625)
		return (1);
	return (0);
}

double	iterate_mandel(t_complex c, int max_iter)
{
	int			iter;
	double		temp;
	double		r2;
	t_complex	z;

	if (max_iter < 750 && in_set(c))
		return (0);
	z.x = 0;
	z.y = 0;
	iter = 0;
	while (iter < max_iter)
	{
		r2 = z.x * z.x + z.y * z.y;
		if (r2 > 4.0)
			break ;
		temp = z.x;
		z.y = 2.0 * temp * z.y + c.y;
		z.x = 2.0 * temp * temp - r2 + c.x;
		iter++;
	}
	if (iter == max_iter)
		return (0);
	if (r2 < 1e-300)
		r2 = 1e-300;
	return (iter + 2.0 - log(log(r2)) * 1.4426950408889634);
}

double	iterate_julia(t_complex c, t_complex z, int max_iter)
{
	int		iter;
	double	temp;
	double	r2;

	iter = 0;
	while (iter < max_iter)
	{
		r2 = z.x * z.x + z.y * z.y;
		if (r2 > 4.0)
			break ;
		temp = z.x;
		z.y = 2.0 * temp * z.y + c.y;
		z.x = 2.0 * temp * temp - r2 + c.x;
		iter++;
	}
	if (iter == max_iter)
		return (0);
	if (r2 < 1e-300)
		r2 = 1e-300;
	return (iter + 2.0 - log(log(r2)) * 1.4426950408889634);
}
