#include "fractol.h"

void	drawing(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (data->v == 3)
				julia(i, j, data);
			else if (data->v == 2)
				burning_ship(i, j, data);
			else if (data->v == 1)
				mandelbrot(i, j, data);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img.p_img, 0, 0);
}

int	key_press_action(int k, t_data *data)
{
	if (k == 53)
	{
		mlx_destroy_image(data->mlx, data->img.p_img);
		mlx_destroy_window(data->mlx, data->mlx_window);
		free(data);
		exit(0);
	}
	else if (k == 124)
		data->s.x += 0.05 * (data->dir.x_p - data->dir.x_n);
	else if (k == 123)
		data->s.x -= 0.05 * (data->dir.x_p - data->dir.x_n);
	else if (k == 125)
		data->s.y -= 0.05 * (data->dir.y_p - data->dir.y_n);
	else if (k == 126)
		data->s.y += 0.05 * (data->dir.y_p - data->dir.y_n);
	else if (k == 78)
		data->max_it -= 10;
	else if (k == 69)
		data->max_it += 10;
	else
		return (0);
	drawing(data);
	return (0);
}

int	mouse(int k, int x, int y, t_data *data)
{
	double	x_map;
	double	y_map;

	x_map = to_another_range(x, data->dir.x_n, data->dir.x_p, WIDTH);
	y_map = to_another_range(y, data->dir.y_p, data->dir.y_n, HEIGHT);
	if (k == 4)
	{
		data->z = 0.9;
	}
	else if (k == 5)
	{
		data->z = 1.1;
	}
	else
		return (0);
	data->dir.x_p = x_map + (data->dir.x_p - x_map) * data->z;
	data->dir.x_n = x_map + (data->dir.x_n - x_map) * data->z;
	data->dir.y_p = y_map + (data->dir.y_p - y_map) * data->z;
	data->dir.y_n = y_map + (data->dir.y_n - y_map) * data->z;
	drawing(data);
	return (0);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.p_img);
	mlx_destroy_window(data->mlx, data->mlx_window);
	free(data);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = check_fractol(argc, argv);
	drawing(data);
	mlx_key_hook(data->mlx_window, key_press_action, data);
	mlx_mouse_hook(data->mlx_window, mouse, data);
	mlx_hook(data->mlx_window, 17, 0, on_destroy, data);
	mlx_loop(data->mlx);
	return (0);
}
