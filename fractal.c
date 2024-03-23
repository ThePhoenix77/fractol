#include "fractol.h"

int mouse_move(int x, int y, t_fractol *fractol)
{
    if (x < 600 && y < 600 && fractol->stop == 0 && ft_strcmp(fractol->name, "julia") == 0)
    {
        fractol->x_o = (((double)x / 600) * 4) - 2;
        fractol->y_o = (((double)y * -1 / 600) * 4) + 2;
        check_ar(fractol);
    }
    return (1);
}

void mlx_ho(t_fractol *fractol)
{
    menu(fractol);
    mlx_hook(fractol->win, 4, 1, mouse_press, fractol);
	mlx_hook(fractol->win, 6, 1, mouse_move, fractol);
	mlx_hook(fractol->win, 2, 1, key_press, fractol);
	mlx_loop(fractol->ptr);
}

void zoom(t_fractol *fractol, double x, double y, double zoom)
{
    double xp;
    double yp;
    
    xp = ((x / WIDTH) * (fractol->end_x - fractol->start_x)) + fractol->start_x;
    yp = ((y / HIGHT) * (fractol->end_y - fractol->start_y)) + fractol->start_y;

    fractol->start_x = xp + ((fractol->start_x - xp) * zoom);
    fractol->start_y = yp + ((fractol->start_y - yp) * zoom);
    fractol->end_x = xp + ((fractol->end_x - xp) * zoom);
    fractol->end_y = yp + ((fractol->end_y - yp) * zoom);
    if (fractol->max <= 120)
        fractol->max +=2;
}

void mandelbrot(t_fractol *fractol)
{
    mlx_clear_window(fractol->ptr, fractol->win);
    fractol->y_y = 0;
    while (fractol->y_y < HIGHT)
    {
        fractol->x_x = 0;
        while (fractol->x_x < WIDTH)
        {
            fractol->iter = 0;
            map(fractol);
            iter_loop(fractol);
            if (fractol->iter == fractol->max)
                set_color(fractol, 0);
            else
                set_color(fractol, 1);
            fractol->x_x++;
        }
        fractol->y_y++;
    }
    fractol->stop = 1;
    mlx_ho(fractol);
}

void julia(t_fractol *fractol)
{
    mlx_clear_window(fractol->ptr, fractol->win);
    fractol->y_y = 0;
    while (fractol->y_y < WIDTH)
    {
        fractol->x_x = 0;
        while (fractol->x_x < HIGHT)
        {
            fractol->iter = 0;
            init_x_y(fractol);
            iter_loop(fractol);
            if (fractol->iter == fractol->max)
				set_color(fractol, 0);
			else
				set_color(fractol, 1);
			fractol->x_x++;
        }
        fractol->y_y++;
    }
    mlx_ho(fractol);
}

