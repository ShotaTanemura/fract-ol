/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:52:09 by shtanemu          #+#    #+#             */
/*   Updated: 2023/01/29 01:52:09 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_data {
	void	*img;
	int		x;
	int		y;
	int		img_width;
	int		img_height;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	*img;
}				t_vars;

int	set_xy(int x, int y, t_data *img)
{
	img->x = x;
	img->y = y;
	return (0);
}

int	put_cursor(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
	return (0);
}

int	main(void)
{
	char	*relative_path = "./src/test.xpm";
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1500, 800, "Hello world!");
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img.img_width, &img.img_height);
	vars.img = &img;
	vars.img->x = 10;
	vars.img->y = 10;
	// mlx_hook(vars.win, 7, 1L<<4, put_cursor, &vars.img);
	mlx_hook(vars.win, 6, 1L<<6, set_xy, &vars.img);
	mlx_loop_hook(vars.mlx, put_cursor, &vars);
	mlx_loop(vars.mlx);
}
