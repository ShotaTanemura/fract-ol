/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burningship_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:13:40 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 18:39:48 by shtanemu         ###   ########.fr       */
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
		main_burningship(vars, vars->scale_factor);
	}
	return (0);
}

void	draw_burningship(int argc, char **argv)
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
	vars.move_x = 0.0;
	vars.move_y = 0.0;
	vars.scale_factor = 0.01;
	main_burningship(&vars, vars.scale_factor);
	mlx_mouse_hook(vars.win, scale_with_mouse_wheel, &vars);
	mlx_key_hook(vars.win, key_events, &vars);
	mlx_hook(vars.win, 17, 0, exit_fractol, &vars);
	mlx_loop(vars.mlx);
}
