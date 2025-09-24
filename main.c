/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 01:08:26 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/24 03:57:45 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_input(t_param *p, int argc, char **argv)
{
	char	*msg;
	t_format	form_x;
	t_format	form_y;

	(void)p;
	msg = "Error: Invalid input\nusage: ./fract-ol"
		"-m(Mandelbrot)\n   or: ./fract-ol -j(Julia) <x> <yi>\n";
	if (argc == 2 && (!ft_strncmp(argv[1], "-m", ft_strlen(argv[1]))
			|| !ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1]))
			|| !ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1]))))
		return (1);
	if (argc == 4 && (!ft_strncmp(argv[1], "-j", ft_strlen(argv[1]))
			|| !ft_strncmp(argv[1], "Julia", ft_strlen(argv[1]))
			|| !ft_strncmp(argv[1], "julia", ft_strlen(argv[1]))))
	{
		valid_input(argv[2], argv[3], &form_x, &form_y);
		// p->c = parse_input(argv[2], argv[3]);
		return (0);
	}
	ft_putstr_fd(msg, 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_param	param;

	param.mandel = check_input(&param, argc, argv);
	// param.mlx = mlx_init();
	// if (param.mandel)
	// 	param.win = mlx_new_window(param.mlx, 821, 921, "Mandelbrot fract-ol");
	// else
	// 	param.win = mlx_new_window(param.mlx, 821, 921, "Julia fract-ol");
	// param.width = 821;
	// param.hight = 921;
	// param.redraw = 1;
	// param.zoom = 1;
	// param.img = NULL;
	// param.x_len = 6;
	// param.y_len = (param.hight * param.x_len) / param.width;
	// param.x_start = 3;
	// param.y_start = param.y_len / 2;
	// hook_all_events(&param);
	// mlx_loop(param.mlx);
}
