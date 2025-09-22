/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 01:08:26 by farmoham          #+#    #+#             */
/*   Updated: 2025/09/22 04:43:53 by farmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_input(int argc, char **argv)
{
	if (!(argc == 2 || argc == 4))
	{
		ft_putstr_fd("Error: Invalid input\nusage: ", 2);
		ft_putstr_fd("./fract-ol -m(Mandelbrot)\n", 2);
		ft_putstr_fd("   or: ./fract-ol -j(Julia) <x> <y>\n", 2);
		exit(1);
	}
	if (argc == 2 && (!ft_strncmp(argv[1], "-m", ft_strlen(argv[1]))
			|| !ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1]))
			|| !ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1]))))
		return (1);
	if (argc == 4 && (!ft_strncmp(argv[1], "-j", ft_strlen(argv[1]))
			|| !ft_strncmp(argv[1], "Julia", ft_strlen(argv[1]))
			|| !ft_strncmp(argv[1], "julia", ft_strlen(argv[1]))))
		return (0);
	else
	{
		ft_putstr_fd("Error: Invalid input\nusage: ", 2);
		ft_putstr_fd("./fract-ol -m(Mandelbrot)\n", 2);
		ft_putstr_fd("   or: ./fract-ol -j(Julia) <x> <y>\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_param	param;

	param.mandel = check_input(argc, argv);
	param.mlx = mlx_init();
	if (param.mandel)
		param.win = mlx_new_window(param.mlx, 821, 921, "Mandelbrot fract-ol");
	else
		param.win = mlx_new_window(param.mlx, 821, 921, "Julia fract-ol");
	hook_all_events(&param);
	mlx_loop(param.mlx);
}
