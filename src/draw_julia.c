/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 02:42:06 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 03:29:30 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	scale_with_mouse_wheel(int keycode, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (keycode == 4 || keycode == 5)
	{
		if (keycode == 4)
			vars->scale_factor -= (vars->scale_factor * 0.1);
		else
			vars->scale_factor += (vars->scale_factor * 0.1);
		main_julia(vars, vars->scale_factor);
	}
	return (0);
}

void	set_params(t_vars *vars, double seed1, double seed2)
{
	vars->param1 = -1.5;
	while (seed1)
	{
		vars->param1 += 0.001;
		seed1--;
	}
	vars->param2 = 1.5;
	while (seed2)
	{
		vars->param2 -= 0.001;
		seed2--;
	}
}

void	draw_julia(long seed1, long seed2)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "frac-tol");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	vars.img = &img;
	vars.scale_factor = 0.01;
	set_params(&vars, seed1, seed2);
	main_julia(&vars, vars.scale_factor);
	mlx_mouse_hook(vars.win, scale_with_mouse_wheel, &vars);
	mlx_key_hook(vars.win, close_window, &vars);
	mlx_hook(vars.win, 17, 0, exit_fractol, &vars);
	mlx_loop(vars.mlx);
}
