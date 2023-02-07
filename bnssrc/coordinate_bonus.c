/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:11:00 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 18:39:30 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	set_horizontal(t_coord *coord, t_vars *vars)
{
	coord->x = 0;
	coord->a = coord->x -325 * vars->scale_factor + \
							vars->move_x * vars->scale_factor;
}

void	set_vertical(t_coord *coord, t_vars *vars)
{
	coord->y = 0;
	coord->b = coord->y -310 * vars->scale_factor + \
							vars->move_y * vars->scale_factor;
}

void	increment_vertical(t_coord *coord)
{
	coord->y++;
	coord->b += coord->complex_unit;
}

void	increment_horizontal(t_coord *coord)
{
	coord->x++;
	coord->a += coord->complex_unit;
}
