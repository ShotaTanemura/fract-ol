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

void	main_fractol(int argc, char **argv)
{
	if (validate_args(argc, argv))
	{
		if (argc == 4 && is_julia_set(argv))
			draw_julia(ft_atol(argv[2]), ft_atol(argv[3]));
		else if (is_mandelbrot_set(argv[1]))
			draw_mandelbrot();
	}
}
