/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caliculate_zk_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:02:14 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 15:31:03 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex	calculate_zk_plus_one(t_complex zk, t_complex c)
{
	return (add_complex(mul_complex(zk, zk), c));
}

t_complex	calculate_zk_plus_one_burningship(t_complex zk, t_complex c)
{
	t_complex	abs_zk;

	abs_zk = abs_complex_burningship(zk);
	return (add_complex(mul_complex(abs_zk, \
						mul_complex(abs_zk, \
						mul_complex(abs_zk, \
						mul_complex(abs_zk, abs_zk)))), c));
}

bool	is_diverged(t_complex zk_plus_one)
{
	return (abs_complex(zk_plus_one) > 2.00);
}
