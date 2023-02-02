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

bool	is_julia_set(char *arg)
{
	return ((bool)(ft_strlen(arg) == 5 && !ft_strncmp(arg, "julia", 5)));
}

bool	is_mandelbrot_set(char *arg)
{
	return ((bool)(ft_strlen(arg) == 10 && !ft_strncmp(arg, "mandelbrot", 10)));
}

bool	validate_args(int argc, char **argv)
{
	if (2 == argc)
	{
		if (is_julia_set(argv[1]) || is_mandelbrot_set(argv[1]))
			return (true);
	}
	print_usage();
	return (false);
}

void	main_fractol(int argc, char **argv)
{
	if (validate_args(argc, argv))
	{
		if (is_julia_set(argv[1]))
			return ;
			// draw_julia();
		else if (is_mandelbrot_set(argv[1]))
			draw_mandelbrot();
	}
}
