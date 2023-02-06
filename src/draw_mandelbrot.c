/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:40:08 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 03:32:54 by shtanemu         ###   ########.fr       */
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
		main_mandelbrot(vars, vars->scale_factor);
	}
	return (0);
}

void	draw_mandelbrot(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "frac-tol");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	vars.img = &img;
	vars.scale_factor = 0.1;
	main_mandelbrot(&vars, vars.scale_factor);
	mlx_mouse_hook(vars.win, scale_with_mouse_wheel, &vars);
	mlx_key_hook(vars.win, close_window, &vars);
	mlx_hook(vars.win, 17, 0, exit_fractol, &vars);
	mlx_loop(vars.mlx);
}
