/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:02:38 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 18:40:34 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

void	draw_mandelbrot(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "frac-tol");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	vars.img = &img;
	vars.argv = argv;
	vars.argc = argc;
	vars.move_x = 0;
	vars.move_y = 0;
	vars.scale_factor = 0.1;
	mlx_mouse_hook(vars.win, scale_with_mouse_wheel, &vars);
	mlx_key_hook(vars.win, key_events, &vars);
	mlx_hook(vars.win, 17, 0, exit_fractol, &vars);
	main_mandelbrot(&vars, vars.scale_factor);
	mlx_loop(vars.mlx);
}
