/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:03:11 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 15:03:11 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	main_fractol(int argc, char **argv)
{
	if (validate_args(argc, argv))
	{
		if (is_julia_set(argc, argv))
			draw_julia(argc, argv, ft_atol(argv[2]), ft_atol(argv[3]));
		else if (is_mandelbrot_set(argc, argv[1]))
			draw_mandelbrot(argc, argv);
		else if (is_burningship_set(argc, argv[1]))
			draw_burningship(argc, argv);
	}
}
