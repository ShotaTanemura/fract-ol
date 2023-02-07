/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:03:32 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 15:31:03 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	print_usage(void)
{
	ft_putendl_fd("\n", 1);
	ft_putendl_fd("Usage: ./fractol mandelbrot\n", 1);
	ft_putstr_fd("       ", 1);
	ft_putendl_fd("./fractol julia [seed1] [seed2]", 1);
	ft_putstr_fd("       - you can pass only natural number ", 1);
	ft_putstr_fd("between 0 and 3000 without sign.\n", 1);
	ft_putstr_fd("       ", 1);
	ft_putendl_fd("./fractol burningship", 1);
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

bool	validate_args(int argc, char **argv)
{
	if (is_mandelbrot_set(argc, argv[1]))
		return (true);
	if (is_burningship_set(argc, argv[1]))
		return (true);
	if (is_julia_set(argc, argv))
		return (true);
	print_usage();
	return (false);
}
