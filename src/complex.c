/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:07:00 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/03 03:08:30 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex   mul_complex(t_complex c1, t_complex c2)
{
    t_complex result;

    result.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    result.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return (result);
}

t_complex   add_complex(t_complex c1, t_complex c2)
{
    t_complex result;

    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return (result);
}

double   abs_complex(t_complex c)
{
    return (sqrt(pow(c.real, 2) + pow(c.imag, 2)));
}

t_complex   create_complex_from_int(double x, double y)
{
    t_complex   complex;

    complex.real = x;
    complex.imag = y;
    return (complex);
}
