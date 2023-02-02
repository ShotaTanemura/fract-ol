/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 05:48:30 by shtanemu          #+#    #+#             */
/*   Updated: 2023/01/21 05:48:30 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// #include <mlx.h>

typedef struct	s_data {
	void	*img;
	int		trgb;
	int		x;
	int		y;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	*img;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	add_shade(double distance, int trgb)
{
	int	t;
	int	r;
	int	g;
	int	b;

	distance = 1 - distance;
	t = get_t(trgb);
	r = get_r(trgb) * distance;
	g = get_g(trgb) * distance;
	b = get_b(trgb) * distance;
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_opposite(int trgb)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_t(trgb);
	r = 255 - get_r(trgb);
	g = 255 - get_g(trgb);
	b = 255 - get_b(trgb);
	return (t << 24 | r << 16 | g << 8 | b);
}


int	my_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	ft_putnbr_fd(keycode, 1);
	printf("\n");
	return (0);
}

int press_hook(int button, t_vars *vars)
{
	if (button == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	ft_putnbr_fd(button, 1);
	printf("\n");
	return (0);
}

int	mouse_hook(int x, int y, t_vars *vars)
{
	if (x < 0)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	ft_putnbr_fd(x, 1);
	printf("\n");
	ft_putnbr_fd(y, 1);
	printf("\n");
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	int	t;
	int	r;
	int	g;
	int	b;
	size_t	x;
	size_t	y;

	t = get_t(vars->img->trgb);
	r = get_r(vars->img->trgb);
	g = get_g(vars->img->trgb);
	b = get_b(vars->img->trgb);
	if (r == 255)
	{
		r = 0;
		g = 255;
		b = 0;
	}
	else if (g == 255)
	{
		r = 0;
		g = 0;
		b = 255;
	}
	else if (b == 255)
	{
		r = 255;
		g = 0;
		b = 0;
	}
	vars->img->trgb = create_trgb(t, r, g, b);
	// vars->img->trgb = get_opposite(vars->img->trgb);
	x = 10;
	y = 10;
	while (x < 500)
	{
		y = 10;
		while (y < 500)
		{
			my_mlx_pixel_put(vars->img, x, y, vars->img->trgb);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

int	move(int keycode, t_vars *vars)
{
	if (keycode == 119)
		vars->img->y--;
	else if (keycode == 97)
		vars->img->x--;
	else if (keycode == 115)
		vars->img->y++;
	else if (keycode == 100)
		vars->img->x++;
	return (0);
}

int	render(t_vars *vars)
{
	size_t	x;
	size_t	y;

	vars->img->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_length,
								&vars->img->endian);
	x = 10;
	while (x < 110)
	{
		y = 10;
		while (y < 110)
		{
			my_mlx_pixel_put(vars->img, vars->img->x + x, vars->img->y + y, vars->img->trgb);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

int	main(void)
{
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;
	// size_t	x;
	// size_t	y;
	// int		trgb;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// x = 10;
	// trgb = create_trgb(0, 100, 0, 40);
	// trgb = add_shade(0.5, trgb);
	// trgb = get_opposite(trgb);
	// while (x < 500)
	// {
	// 	y = 10;
	// 	while (y < 500)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, trgb);
	// 		y++;
	// 	}
	// 	x++;
	// }
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);

	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img.trgb = create_trgb(0, 255, 0, 0);
	vars.img = &img;
	// mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	// mlx_loop_hook(vars.mlx, move_circle, &vars);
	vars.img->x = 50;
	vars.img->y = 50;
	mlx_key_hook(vars.win, move, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	// img.trgb = create_trgb(0, 100, 0, 40);
	// my_mlx_pixel_put(&img, 5, 5, img.trgb);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

// mlx_hook(vars.win, 25, 1L<<18, print_hello, &vars);
// mlx_hook(vars.win, 2, 1L<<0, &my_close, &vars);
// mlx_hook(vars.win, 33, 1L<<17, &my_close, &vars);
// mlx_key_hook(vars.win, key_hook, &vars);
// mlx_hook(vars.win, 6, 1L<<6, mouse_hook, &vars);
