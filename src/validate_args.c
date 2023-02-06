/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:55:29 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 02:53:43 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_putendl_fd("\n", 1);
	ft_putendl_fd("Usage: ./fractol mandelbrot\n", 1);
	ft_putstr_fd("       ", 1);
	ft_putendl_fd("./fractol julia [seed1] [seed2]", 1);
	ft_putstr_fd("       - you can pass only natural number ", 1);
	ft_putstr_fd("between 0 and 3000 without sign.", 1);
	ft_putendl_fd("\n", 1);
}

bool	validate_julia_options(char **argv)
{
	size_t	i;

	i = 0;
	if (argv[2][0] == '0' && argv[2][1])
		return (false);
	if (argv[3][0] == '0' && argv[3][1])
		return (false);
	while (argv[2][i])
	{
		if (!ft_isdigit(argv[2][i]))
			return (false);
		i++;
	}
	i = 0;
	while (argv[3][i])
	{
		if (!ft_isdigit(argv[3][i]))
			return (false);
		i++;
	}
	if (ft_atol(argv[2]) > 3000 || ft_atol(argv[3]) > 3000)
		return (false);
	if (0 > ft_atol(argv[2]) || 0 > ft_atol(argv[3]))
		return (false);
	return (true);
}

bool	is_julia_set(char **argv)
{
	if (!validate_julia_options(argv))
		return (false);
	if (ft_strlen(argv[1]) != 5)
		return (false);
	return ((bool) !ft_strncmp(argv[1], "julia", 5));
}

bool	is_mandelbrot_set(char *arg)
{
	if (ft_strlen(arg) != 10)
		return (false);
	return ((bool) !ft_strncmp(arg, "mandelbrot", 10));
}

bool	validate_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (is_mandelbrot_set(argv[1]))
			return (true);
	}
	if (argc == 4)
	{
		if (is_julia_set(argv))
			return (true);
	}
	print_usage();
	return (false);
}
