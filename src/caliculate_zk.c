/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caliculate_zk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:30:19 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/05 20:44:36 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	calculate_zk_plus_one(t_complex zk, t_complex c)
{
	return (add_complex(mul_complex(zk, zk), c));
}

bool	is_diverged(t_complex zk_plus_one)
{
	return (abs_complex(zk_plus_one) > 2.00);
}
