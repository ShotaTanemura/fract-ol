/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:31:20 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/05 20:31:58 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_complex(t_coord *coord, t_vars *vars, t_complex c)
{
	size_t		iterations;
	t_complex	zk;

	zk = create_complex(coord->a, coord->b);
	iterations = 0;
	vars->img->trgb = create_trgb(255, 255, 255, 255);
	while (iterations < MAX_ITER)
	{
		c.imag = vars->param1;
		c.real = vars->param2;
		zk = calculate_zk_plus_one(zk, c);
		if (is_diverged(zk))
		{
			if (5 > iterations)
				vars->img->trgb = create_trgb(0, iterations * 10, \
					iterations * 10, iterations * 10);
			else
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
	t_complex	c;

	set_horizontal(&coord, vars->scale_factor);
	coord.complex_unit = scale_factor;
	c.imag = vars->param1;
	c.real = vars->param2;
	while (coord.x < WIN_WIDTH)
	{
		set_vertical(&coord, vars->scale_factor);
		while (coord.y < WIN_HEIGHT)
		{
			put_complex(&coord, vars, c);
			increment_vertical(&coord);
		}
		increment_horizontal(&coord);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, \
							vars->img->img, 0, 0);
}
