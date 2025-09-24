/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:11:58 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/24 03:58:52 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	scan_number_part(char *nm, t_format *form, int *in_nm, int *i)
{
	while (*in_nm)
	{
		if (!nm[*i])
			break ;
		if (nm[*i] == 'e' || nm[*i] == 'E')
		{
			*in_nm = 0;
			form->e = 1;
		}
		else if (ft_isdigit(nm[*i]))
			form->nm_digits++;
		else if (!form->dot && nm[*i] == '.')
			form->dot = 1;
		else
			return (0);
		(*i)++;
	}
	if (form->nm_digits == 0)
		return (0);
	return (1);
}

int	is_valid(char *nm, t_format *form, int i, int in_nm)
{
	if (nm[i] == '-' || nm[i] == '+')
		form->nm_sign = 44 - nm[i++];
	if (ft_isdigit(nm[i]) || nm[i] == '.')
		in_nm = 1;
	if (nm[i] == '.')
	{
		form->dot = 1;
		i++;
	}
	if (!in_nm)
		return (0);
	if (!scan_number_part(nm, form, &in_nm, &i))
		return (0);
	if (form->e && (nm[i] == '-' || nm[i] == '+'))
		form->e_sign = 44 - nm[i++];
	while (nm[i])
	{
		if (!ft_isdigit(nm[i]))
			return (0);
		form->e_digits++;
		i++;
	}
	if (form->e && !form->e_digits)
		return (0);
	return (1);
}

void	valid_input(char *x, char *y, t_format *form_x, t_format *form_y)
{
	form_x->nm_digits = 0;
	form_x->e_digits = 0;
	form_x->dot = 0;
	form_x->e = 0;
	form_x->e_sign = 1;
	form_x->nm_sign = 1;
	if (is_valid(x, form_x, 0, 0))
	{
		form_y->nm_digits = 0;
		form_y->e_digits = 0;
		form_y->dot = 0;
		form_y->e = 0;
		form_y->e_sign = 1;
		form_y->nm_sign = 1;
		if (is_valid(y, form_y, 0, 0))
			return ;
		ft_putstr_fd("Error: Invalid y input value\n", 2);
	}
	else
		ft_putstr_fd("Error: Invalid x input value\n", 2);
	ft_putstr_fd("Format: [±]digits[.digits][e±digits]  ([] = optional)\n", 2);
	exit(1);
}
