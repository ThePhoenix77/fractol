#include "fractol.h"

void	mandelbrot(int x, int y, t_data *data)
{
	t_cpx	z;
	t_cpx	c;
	int		i;
	int		color;

	z.r = 0;
	z.i = 0;
	i = 0;
	c.r = to_another_range(x, data->dir.x_n, data->dir.x_p, WIDTH) + data->s.x;
	c.i = to_another_range(y, data->dir.y_p, data->dir.y_n, HEIGHT) + data->s.y;
	while (i < data->max_it)
	{
		z = small_equa(z, c);
		if ((pow(z.r, 2) + pow(z.i, 2)) > data->axis)
		{
			color = to_another_range(i, BLACK, PINK, data->max_it);
			my_pixel_put(&data->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&data->img, x, y, BLACK);
}

void	burning_ship(int x, int y, t_data *data)
{
	t_cpx	z;
	t_cpx	c;
	int		i;
	int		color;

	z.r = 0;
	z.i = 0;
	i = 0;
	c.r = to_another_range(x, data->dir.x_n, data->dir.x_p, WIDTH) + data->s.x;
	c.i = to_another_range(y, data->dir.y_p, data->dir.y_n, HEIGHT) + data->s.y;
	while (i < data->max_it)
	{
		z = small_equa(z, c);
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		if ((pow(z.r, 2) + pow(z.i, 2)) > data->axis)
		{
			color = to_another_range(i, BLACK, PINK, data->max_it);
			my_pixel_put(&data->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&data->img, x, y, BLACK);
}
