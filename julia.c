#include "fractol.h"

void	julia(int x, int y, t_data *data)
{
	t_cpx	z;
	t_cpx	c;
	int		i;
	int		color;

	c.r = data->input.r;
	c.i = data->input.i;
	i = 0;
	z.r = to_another_range(x, data->dir.x_n, data->dir.x_p, WIDTH) + data->s.x;
	z.i = to_another_range(y, data->dir.y_p, data->dir.y_n, HEIGHT) + data->s.y;
	while (i < data->max_it)
	{
		z = small_equa(z, c);
		if ((pow(z.r, 2) + pow(z.i, 2)) > data->axis)
		{
			color = to_another_range(i, BLACK, YELLOW, data->max_it);
			my_pixel_put(&data->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&data->img, x, y, BLACK);
}
