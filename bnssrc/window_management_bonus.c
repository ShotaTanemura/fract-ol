/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:03:46 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 15:31:03 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	move_view(int keycode, t_vars *vars)
{
	if (keycode == 126)
		vars->move_y += 10.0;
	else if (keycode == 125)
		vars->move_y -= 10.0;
	else if (keycode == 123)
		vars->move_x += 10.0;
	else if (keycode == 124)
		vars->move_x -= 10.0;
	if (is_mandelbrot_set(vars->argc, vars->argv[1]))
		main_mandelbrot(vars, vars->scale_factor);
	else if (is_julia_set(vars->argc, vars->argv))
		main_julia(vars, vars->scale_factor);
	else if (is_burningship_set(vars->argc, vars->argv[1]))
		main_burningship(vars, vars->scale_factor);
}

void	shift_color(t_vars *vars)
{
	if (vars->color_shift == 0)
		vars->color_shift = 0;
	vars->color_shift++;
	if (vars->color_shift > 255)
		vars->color_shift = 20;
	if (is_mandelbrot_set(vars->argc, vars->argv[1]))
		main_mandelbrot(vars, vars->scale_factor);
	else if (is_julia_set(vars->argc, vars->argv))
		main_julia(vars, vars->scale_factor);
	else if (is_burningship_set(vars->argc, vars->argv[1]))
		main_burningship(vars, vars->scale_factor);
}

int	key_events(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode >= 123 && 126 >= keycode)
		move_view(keycode, vars);
	if (keycode == 49)
		shift_color(vars);
	return (0);
}

int	exit_fractol(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return (0);
}
