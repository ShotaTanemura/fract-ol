/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_which_set_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:02:44 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 15:31:03 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

bool	is_julia_set(int argc, char **argv)
{
	if (argc != 4)
		return (false);
	if (!validate_julia_options(argv))
		return (false);
	if (ft_strlen(argv[1]) != 5)
		return (false);
	return ((bool) !ft_strncmp(argv[1], "julia", 5));
}

bool	is_mandelbrot_set(int argc, char *arg)
{
	if (argc != 2)
		return (false);
	if (ft_strlen(arg) != 10)
		return (false);
	return ((bool) !ft_strncmp(arg, "mandelbrot", 10));
}

bool	is_burningship_set(int argc, char *arg)
{
	if (argc != 2)
		return (false);
	if (ft_strlen(arg) != 11)
		return (false);
	return ((bool) !ft_strncmp(arg, "burningship", 11));
}
