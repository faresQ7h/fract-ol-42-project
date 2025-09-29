/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 02:02:50 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/29 22:10:16 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	exponent(char *nm, int e)
{
	int	i;

	if (!e)
		return (0);
	i = 0;
	while (nm[i] && nm[i] != 'e' && nm[i] != 'E')
		i++;
	return (ft_atoi(&nm[i + 1]));
}

static int	set_non_zero(char *nm, int first)
{
	int	f;
	int	l;

	f = 0;
	while (first)
	{
		if (!(nm[f] == '+' || nm[f] == '-' || nm[f] == '0' || nm[f] == '.'))
			return (f);
		f++;
	}
	l = f;
	while (nm[l])
	{
		if (nm[l] == 'e' || nm[l] == 'E')
			break ;
		l++;
	}
	while (1)
	{
		if (!(nm[l] == '0' || nm[l] == '.' || nm[l] == '\0' || nm[l] == 'e'
				|| nm[l] == 'E'))
			return (l);
		l--;
	}
}

static int	normalize_cost(char *nm, int fnz, int dot)
{
	int	dot_pos;
	int	tail;

	if (!dot)
	{
		tail = 0;
		while (1)
		{
			if (!nm[tail] || (nm[tail] == 'e' || nm[tail] == 'E'))
				break ;
			tail++;
		}
		return (tail - fnz - 1);
	}
	dot_pos = 0;
	while (1)
	{
		if (nm[dot_pos] == '.')
			break ;
		dot_pos++;
	}
	if (fnz < dot_pos)
		return (dot_pos - fnz - 1);
	return (dot_pos - fnz);
}

static double	normalize_nm(char *nm, int fnz, int nm_len)
{
	double	val;
	int		count;

	val = 0;
	count = 1;
	if (nm_len > 17)
		nm_len = 17;
	while (nm_len > 0)
	{
		if (nm[fnz] == '.')
		{
			fnz++;
			continue ;
		}
		val = val * 10 + (nm[fnz] - '0');
		count--;
		nm_len--;
		fnz++;
	}
	return (val * pow(10, count));
}

double	parse_input(char *nm, t_format *form, int nm_len)
{
	int		k;
	int		dot_pos;
	int		lnz;
	int		fnz;
	double	val;

	fnz = set_non_zero(nm, 1);
	if (!nm[fnz] || nm[fnz] == 'e' || nm[fnz] == 'E')
		return (0);
	lnz = set_non_zero(nm, 0);
	dot_pos = 0;
	while (form->dot && nm[dot_pos] != '.')
		dot_pos++;
	if (!form->dot || (fnz < dot_pos && dot_pos < lnz))
		nm_len = lnz - fnz + !(form->dot);
	else
		nm_len = lnz - fnz + 1;
	val = normalize_nm(nm, fnz, nm_len);
	k = exponent(nm, form->e) + normalize_cost(nm, fnz, form->dot);
	if (k > 308 || (k == 308 && val > 1.79769313486231570))
		return (ft_putstr_fd("Error: overflow (double)\n", 2), exit(1), 0);
	else if (k < -324 || (k == -324 && val < 4.9406564584124654))
		return (ft_putstr_fd("Warning: detected double underflow);"
				" treated as 0\n\n", 2), 0);
	return (val * pow(10, k) * form->nm_sign);
}
