/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 03:24:33 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/03 04:36:15 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_horizontal(t_coord *coord)
{
	coord->x = 0;
	coord->a = (coord->x / WIN_WIDTH * 2) - 2.50;
	// coord->a = (coord->x / WIN_WIDTH * coord->zoom_factor) - 1.00;
}

void	set_vertical(t_coord *coord)
{
	coord->y = 0;
	coord->b = (coord->y / WIN_HEIGHT * 2) - 2.50;
	// coord->b = (coord->y / WIN_HEIGHT * coord->zoom_factor) - 1.00;
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
