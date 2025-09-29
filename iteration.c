/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:56:55 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/29 21:25:25 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	iterate_mandel(t_complex c, int max_iter)
{
	int			iter;
	double		temp;
	double		r2;
	t_complex	z;

	iter = 0;
	z.x = 0;
	z.y = 0;
	while ((z.x * z.x + z.y * z.y) <= 4.0 && iter < max_iter)
	{
		iter++;
		temp = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2.0 * temp * z.y + c.y;
	}
	if (iter == max_iter)
		return (0);
	r2 = z.x * z.x + z.y * z.y;
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
	while ((z.x * z.x + z.y * z.y) <= 4.0 && iter < max_iter)
	{
		iter++;
		temp = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = 2.0 * temp * z.y + c.y;
	}
	if (iter == max_iter)
		return (0);
	r2 = z.x * z.x + z.y * z.y;
	if (r2 < 1e-300)
		r2 = 1e-300;
	return (iter + 2.0 - log(log(r2)) * 1.4426950408889634);
}
