/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandelbrot_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:03:22 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 15:31:03 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	put_complex(t_coord *coord, t_vars *vars, t_complex zk)
{
	size_t		iterations;
	t_complex	c;

	c = create_complex(coord->a, coord->b);
	iterations = 0;
	vars->img->trgb = create_trgb(0, 0, 0, 0);
	while (iterations < MAX_ITER)
	{
		zk = calculate_zk_plus_one(zk, c);
		if (is_diverged(zk))
		{
			vars->img->trgb = create_trgb(0, 0, iterations * 3, \
											vars->color_shift);
			break ;
		}
		iterations++;
	}
	my_mlx_pixel_put(vars->img, coord->x, coord->y, vars->img->trgb);
}

void	main_mandelbrot(t_vars	*vars, double scale_factor)
{
	t_coord		coord;
	t_complex	zk;

	set_horizontal(&coord, vars);
	coord.complex_unit = scale_factor;
	while (coord.x < WIN_WIDTH)
	{
		set_vertical(&coord, vars);
		while (coord.y < WIN_HEIGHT)
		{
			zk.imag = 0;
			zk.real = 0;
			put_complex(&coord, vars, zk);
			increment_vertical(&coord);
		}
		increment_horizontal(&coord);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
