/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:03:05 by shtanemu          #+#    #+#             */
/*   Updated: 2023/01/16 22:03:05 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
//////////////////////////////////////
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
//////////////////////////////////////
typedef struct  s_complex
{
    double  real;
    double  imag;
}   t_complex;
//////////////////////////////////////
void	main_fractol(int argc, char **argv);
//////////////////////////////////////
#endif
