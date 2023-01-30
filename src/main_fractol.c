/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:47:31 by shtanemu          #+#    #+#             */
/*   Updated: 2023/01/30 01:47:31 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_putendl_fd("\n", 1);
	ft_putendl_fd("Usage: ./fractol [fractal type]\n", 1);
	ft_putendl_fd("Where:", 1);
	ft_putstr_fd("[fractal type]: ", 1);
	ft_putstr_fd("Specifies the type of fractal to generate. ", 1);
	ft_putendl_fd("Must be one of the types in the list below.\n", 1);
	ft_putendl_fd("		- julia", 1);
	ft_putendl_fd("		- mandelbrot", 1);
	ft_putendl_fd("\n", 1);
}

void	validate_args(int argc, char **argv)
{

	if (2 == argc)
	{
		if (ft_strlen(argv[1]) == 5 && !ft_strncmp(argv[1], "julia", 5))
			return ;
		if (ft_strlen(argv[1]) == 10 && !ft_strncmp(argv[1], "mandelbrot", 10))
			return ;
	}
	print_usage();
	exit(EXIT_FAILURE);
}

void	main_fractol(int argc, char **argv)
{
	validate_args(argc, argv);
}
