#include "fractol.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] && s2[i])
        i++;
    return (s1[i] - s2[i]);
}

double ft_abs(double x)
{
    if (x < 0)
        return (-x);
    return (x);
}

void map(t_fractol *fractol)
{
    fractol->x = fractol->x_x / (WIDTH / (fractol->end_x - fractol->start_x)) + fractol->start_x;
    fractol->y = fractol->y_y / (WIDTH / (fractol->end_y - fractol->start_y)) + fractol->start_y;
    fractol->x_o = fractol->x;
    fractol->y_o = fractol->y;
}

void iter_loop(t_fractol *fractol)
{
    while (fractol->iter < fractol->max)
    {
        fractol->xtmp = (fractol->x * fractol->x) - (fractol->y * fractol->y);
        if(ft_strcmp(fractol->name, "Burningship") == 0)
            fractol->ytmp = ft_abs(2 * fractol->x * fractol->y);
        else
            fractol->ytmp = 2 * fractol->x * fractol->y;
        fractol->x = fractol->xtmp + fractol->x_o;
        fractol->y = fractol->ytmp + fractol->y_o;
        if (fractol->x * fractol->x + fractol->y * fractol->y > 4)
            break;
        fractol->iter++;
    }
}

void set_color(t_fractol *fractol, int color)
{
    fractol->index = (4 * 1000 * fractol->y_y) + fractol->x_x * 4;
    fractol->ch[fractol->index] = (fractol->iter * fractol->color + 680 + 179) * color;
    fractol->ch[fractol->index + 1] = (fractol->iter * fractol->color + 42 + 84) * color;
    fractol->ch[fractol->index + 2] = (fractol->iter * fractol->color + 680 + 179) * color;
    fractol->ch[fractol->index + 3] = 0;
}
