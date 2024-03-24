#include "fractol.h"

void		simple_zoome1(t_fractol *fractol)
{
	if (fractol->start_x < 0 && fractol->start_y < 0 && fractol->end_x > 0 && fractol->end_y > 0)
	{
		fractol->start_x = fractol->start_x + 0.015;
		fractol->start_y = fractol->start_y + 0.015;
		fractol->end_x = fractol->end_x - 0.015;
		fractol->end_y = fractol->end_y - 0.015;
	}
}

void		simple_zoome2(t_fractol *fractol)
{
	fractol->start_x = fractol->start_x - 0.040;
	fractol->start_y = fractol->start_y - 0.040;
	fractol->end_x = fractol->end_x + 0.040;
	fractol->end_y = fractol->end_y + 0.040;
}

void		init_x_y(t_fractol *fractol)
{
	fractol->x = ((fractol->x_x / (double)WIDTH) *
	(fractol->end_x - fractol->start_x)) + fractol->start_x;
	fractol->y = ((fractol->y_y / (double)HIGHT) *
	(fractol->end_y - fractol->start_y)) + fractol->start_y;
}

void		string1_put(t_fractol *fractol)
{
	mlx_string_put(fractol->ptr, fractol->win, 650, 10, 0xFFFFFF,
			"-------------ZOOM-------------");
	mlx_string_put(fractol->ptr, fractol->win, 650, 40, 0xf7b079,
			"             +   -              ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 40, 0xFFFF00,
			"               |");
	mlx_string_put(fractol->ptr, fractol->win, 650, 500, 0xFFFFFF,
			"-----------ITERATION----------");
	mlx_string_put(fractol->ptr, fractol->win, 650, 520, 0xf7b079,
			"             +   -              ");
	mlx_string_put(fractol->ptr, fractol->win, 650, 520, 0xFFFF00,
			"               |");
}

void		destroy_exit(t_fractol *fractol)
{
	mlx_destroy_image(fractol->ptr, fractol->image);
	mlx_destroy_window(fractol->ptr, fractol->win);
	free(fractol->ptr);
}
