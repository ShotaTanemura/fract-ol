/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:10:10 by shtanemu          #+#    #+#             */
/*   Updated: 2023/02/03 04:34:26 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex   calculate_zk_plus_one(t_complex zk, t_complex c)
{
    return add_complex(mul_complex(zk, zk), c);
}

bool    is_diverged(t_complex zk_plus_one)
{
    return (abs_complex(zk_plus_one) > 2.00);
}

void    draw_pixel(t_coord coordinate)
{
    printf("%f + %fi\n", coordinate.a, coordinate.b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	get_pixel_color(size_t	iterations)
// {
	
// }

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	main_mandelbrot(t_vars	*vars)
{
    size_t  	iterations;
	t_coord		coord;
    t_complex	zk;
    t_complex	c;

	set_horizontal(&coord);
	coord.complex_unit = 0.01;
    while (coord.x < 400)
    {
		set_vertical(&coord);
        while (coord.y < 400)
        {
            zk.imag = 0;
            zk.real = 0;
            c = create_complex_from_int(coord.a, coord.b);
			iterations = 0;
            while (iterations < MAX_ITER)
            {
                zk = calculate_zk_plus_one(zk, c);
                if (is_diverged(zk))
                {
                    // draw_pixel(coord);
					vars->img->trgb = create_trgb(0, 255, 0, 0);
					my_mlx_pixel_put(vars->img, coord.x, coord.y, vars->img->trgb);
                    break ;
                }
                iterations++;
            }
            increment_vertical(&coord);
        }
		increment_horizontal(&coord);
    }
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
