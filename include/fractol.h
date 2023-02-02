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
# include <mlx.h>
//////////////////////////////////////
# ifndef WIN_WIDTH
#  define WIN_WIDTH 768
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 500
# endif

# ifndef MAX_ITER
#  define MAX_ITER 1000
# endif
//////////////////////////////////////
typedef struct  s_complex
{
    double  real;
    double  imag;
}   t_complex;

typedef struct  s_coord
{
    int		x;
    int		y;
	double	a;
	double	b;
	double	complex_unit;
	double	zoom_factor;
}   t_coord;

typedef struct	s_data {
	void	*img;
	int		trgb;
	int		x;
	int		y;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	*img;
}	t_vars;
//////////////////////////////////////
void	main_fractol(int argc, char **argv);
void	main_mandelbrot(t_vars	*vars);
void	draw_mandelbrot(void);
//////////////////////////////////////
// complex.c
//////////////////////////////////////
t_complex   add_complex(t_complex c1, t_complex c2);
t_complex   mul_complex(t_complex c1, t_complex c2);
t_complex   create_complex_from_int(double x, double y);
double   	abs_complex(t_complex c);
//////////////////////////////////////
// coordinate.c
//////////////////////////////////////
void	set_horizontal(t_coord *coord);
void	set_vertical(t_coord *coord);
void	increment_vertical(t_coord *coord);
void	increment_horizontal(t_coord *coord);
//////////////////////////////////////
#endif
