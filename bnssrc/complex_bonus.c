/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:02:20 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 15:31:03 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex	mul_complex(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.real = (c1.real * c2.real) - (c1.imag * c2.imag);
	result.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
	return (result);
}

t_complex	add_complex(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.real = c1.real + c2.real;
	result.imag = c1.imag + c2.imag;
	return (result);
}

double	abs_complex(t_complex c)
{
	return (sqrt(pow(c.real, 2) + pow(c.imag, 2)));
}

t_complex	abs_complex_burningship(t_complex c)
{
	t_complex	ret_c;

	ret_c.real = sqrt(pow(c.real, 2));
	ret_c.imag = sqrt(pow(c.imag, 2));
	return (ret_c);
}

t_complex	create_complex(double a, double b)
{
	t_complex	complex;

	complex.real = a;
	complex.imag = b;
	return (complex);
}
