#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 800, 600, "Hellow World!");
	mlx_loop(mlx);
}
