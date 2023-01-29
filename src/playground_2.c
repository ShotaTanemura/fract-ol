#include "fractol.h"

int	print_code(int	keycode)
{
	ft_putnbr_fd(keycode, 2);
	ft_putendl_fd("test", 2);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1500, 850, "test");
	mlx_hook(win, 2, 0L, print_code, mlx);
	mlx_loop(mlx);
	return (0);
}
