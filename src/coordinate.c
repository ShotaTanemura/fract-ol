/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 03:24:33 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 02:12:16 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_horizontal(t_coord *coord, double scale_factor)
{
	coord->x = 0;
	coord->a = coord->x - 325 * scale_factor;
}

void	set_vertical(t_coord *coord, double scale_factor)
{
	coord->y = 0;
	coord->b = coord->y - 310 * scale_factor;
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
