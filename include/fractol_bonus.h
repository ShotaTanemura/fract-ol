/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:32:03 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/07 15:32:03 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
//////////////////////////////////////
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <mlx.h>
# include "libft.h"
//////////////////////////////////////
# ifndef WIN_WIDTH
#  define WIN_WIDTH 600
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 600
# endif

# ifndef MAX_ITER
#  define MAX_ITER 100
# endif

# ifndef MAX_ITER_BS
#  define MAX_ITER_BS 30
# endif
//////////////////////////////////////
typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_coord
{
	int		x;
	int		y;
	double	a;
	double	b;
	double	complex_unit;
	double	zoom_factor;
}	t_coord;

typedef struct s_data
{
	void	*img;
	int		trgb;
	int		x;
	int		y;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	*img;
	char	**argv;
	int		argc;
	size_t	color_shift;
	double	scale_factor;
	double	param1;
	double	param2;
	double	move_x;
	double	move_y;
}	t_vars;

//////////////////////////////////////
void		main_fractol(int argc, char **argv);
void		main_mandelbrot(t_vars *vars, double scale_factor);
void		draw_mandelbrot(int argc, char **argv);
void		main_julia(t_vars *vars, double scale_factor);
void		draw_julia(int argc, char **argv, long seed1, long seed2);
void		main_burningship(t_vars *vars, double scale_factor);
void		draw_burningship(int argc, char **argv);
t_complex	calculate_zk_plus_one(t_complex zk, t_complex c);
t_complex	calculate_zk_plus_one_burningship(t_complex zk, t_complex c);
bool		is_diverged(t_complex zk_plus_one);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
//////////////////////////////////////
// argument_validation
//////////////////////////////////////
bool		is_julia_set(int argc, char **argv);
bool		is_mandelbrot_set(int argc, char *arg);
bool		is_burningship_set(int argc, char *arg);
bool		validate_args(int argc, char **argv);
bool		validate_julia_options(char **argv);
//////////////////////////////////////
// window_management.c
//////////////////////////////////////
int			key_events(int keycode, t_vars *vars);
int			exit_fractol(t_vars *vars);
void		move_view(int keycode, t_vars *vars);
//////////////////////////////////////
// complex.c
//////////////////////////////////////
t_complex	add_complex(t_complex c1, t_complex c2);
t_complex	mul_complex(t_complex c1, t_complex c2);
t_complex	create_complex(double a, double b);
double		abs_complex(t_complex c);
t_complex	abs_complex_burningship(t_complex c);
//////////////////////////////////////
// coordinate.c
//////////////////////////////////////
void		set_horizontal(t_coord *coord, t_vars *vars);
void		set_vertical(t_coord *coord, t_vars *vars);
void		increment_vertical(t_coord *coord);
void		increment_horizontal(t_coord *coord);
void		set_double_from_seeds(t_coord *coord, t_vars vars);
//////////////////////////////////////
#endif
