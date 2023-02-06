/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:31:20 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 03:03:51 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_complex(t_coord *coord, t_vars *vars)
{
	size_t		iterations;
	t_complex	zk;
	t_complex	c;

	zk = create_complex(coord->a, coord->b);
	iterations = 0;
	vars->img->trgb = create_trgb(0, 255, 255, 255);
	while (iterations < MAX_ITER)
	{
		c.real = vars->param1;
		c.imag = vars->param2;
		zk = calculate_zk_plus_one(zk, c);
		if (is_diverged(zk))
		{
			vars->img->trgb = create_trgb(0, pow(iterations, 2), \
				pow(iterations, 2), pow(iterations, 2));
			break ;
		}
		iterations++;
	}
	my_mlx_pixel_put(vars->img, coord->x, coord->y, vars->img->trgb);
}

void	main_julia(t_vars *vars, double scale_factor)
{
	t_coord		coord;

	set_horizontal(&coord, vars->scale_factor);
	coord.complex_unit = scale_factor;
	while (coord.x < WIN_WIDTH)
	{
		set_vertical(&coord, vars->scale_factor);
		while (coord.y < WIN_HEIGHT)
		{
			put_complex(&coord, vars);
			increment_vertical(&coord);
		}
		increment_horizontal(&coord);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, \
							vars->img->img, 0, 0);
}
