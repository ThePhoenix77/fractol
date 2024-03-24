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
    // fractol->index = (4 * 1000 * fractol->y_y) + fractol->x_x * 4;
    // fractol->ch[fractol->index] = (fractol->iter * fractol->color - 473 + 765) * color;
    // fractol->ch[fractol->index + 1] = (fractol->iter * fractol->color - 449 + 765) * color;
    // fractol->ch[fractol->index + 2] = (fractol->iter * fractol->color - 473 + 765) * color;
    // fractol->ch[fractol->index + 3] = (fractol->iter * fractol->color - 416 + 765) * color;
    // fractol->ch[fractol->index + 4] = (fractol->iter * fractol->color - 489 + 765) * color;
    // fractol->ch[fractol->index + 5] = (fractol->iter * fractol->color - 475 + 765) * color;
    // fractol->ch[fractol->index + 6] = (fractol->iter * fractol->color - 435 + 765) * color;
    // fractol->ch[fractol->index + 7] = 0;

    // fractol->index = (4 * 1000 * fractol->y_y) + fractol->x_x * 4;
    // fractol->ch[fractol->index] = (fractol->iter * fractol->color - 400 + 765) * color;     // Red
    // fractol->ch[fractol->index + 1] = (fractol->iter * fractol->color - 300 + 765) * color; // Orange
    // fractol->ch[fractol->index + 2] = (fractol->iter * fractol->color - 200 + 765) * color; // Yellow
    // fractol->ch[fractol->index + 3] = (fractol->iter * fractol->color - 100 + 765) * color; // Green
    // fractol->ch[fractol->index + 4] = (fractol->iter * fractol->color + 0 + 765) * color;   // Blue
    // fractol->ch[fractol->index + 5] = (fractol->iter * fractol->color + 100 + 765) * color; // Indigo
    // fractol->ch[fractol->index + 6] = (fractol->iter * fractol->color + 200 + 765) * color; // Violet
    // fractol->ch[fractol->index + 7] = 0;

    // fractol->index = (4 * 1000 * fractol->y_y) + fractol->x_x * 4;
    // fractol->ch[fractol->index] = (fractol->iter * fractol->color + 100 + 765) * color;     // Red
    // fractol->ch[fractol->index + 1] = (fractol->iter * fractol->color - 50 + 765) * color;  // Green
    // fractol->ch[fractol->index + 2] = (fractol->iter * fractol->color + 200 + 765) * color; // Blue
    // fractol->ch[fractol->index + 3] = (fractol->iter * fractol->color - 150 + 765) * color; // Yellow
    // fractol->ch[fractol->index + 4] = (fractol->iter * fractol->color + 50 + 765) * color;  // Purple
    // fractol->ch[fractol->index + 5] = (fractol->iter * fractol->color - 100 + 765) * color; // Cyan
    // fractol->ch[fractol->index + 6] = (fractol->iter * fractol->color + 150 + 765) * color; // Pink
    // fractol->ch[fractol->index + 7] = 0;

    // fractol->index = (4 * 1000 * fractol->y_y) + fractol->x_x * 4;
    // fractol->ch[fractol->index] = (fractol->iter * fractol->color + 200 + 765) * color;     // Bright Red
    // fractol->ch[fractol->index + 1] = (fractol->iter * fractol->color + 150 + 765) * color; // Bright Green
    // fractol->ch[fractol->index + 2] = (fractol->iter * fractol->color + 100 + 765) * color; // Bright Blue
    // fractol->ch[fractol->index + 3] = (fractol->iter * fractol->color + 250 + 765) * color; // Bright Yellow
    // fractol->ch[fractol->index + 4] = (fractol->iter * fractol->color + 50 + 765) * color;  // Bright Purple
    // fractol->ch[fractol->index + 5] = (fractol->iter * fractol->color + 200 + 765) * color; // Bright Cyan
    // fractol->ch[fractol->index + 6] = (fractol->iter * fractol->color + 150 + 765) * color; // Bright Pink
    // fractol->ch[fractol->index + 7] = 0;

    // fractol->index = (4 * 1000 * fractol->y_y) + fractol->x_x * 4;
    // fractol->ch[fractol->index] = (fractol->iter * fractol->color + 100 + 765) * color;     // Sky Blue
    // fractol->ch[fractol->index + 1] = (fractol->iter * fractol->color + 200 + 765) * color; // Sunflower Yellow
    // fractol->ch[fractol->index + 2] = (fractol->iter * fractol->color + 150 + 765) * color; // Soft Green
    // fractol->ch[fractol->index + 3] = (fractol->iter * fractol->color + 250 + 765) * color; // Pink
    // fractol->ch[fractol->index + 4] = (fractol->iter * fractol->color + 50 + 765) * color;  // Lavender
    // fractol->ch[fractol->index + 5] = (fractol->iter * fractol->color + 200 + 765) * color; // Pastel Orange
    // fractol->ch[fractol->index + 6] = (fractol->iter * fractol->color + 100 + 765) * color; // Light Coral
    // fractol->ch[fractol->index + 7] = 255;

    // fractol->index = (4 * 1000 * fractol->y_y) + fractol->x_x * 4;
    // fractol->ch[fractol->index] = (fractol->iter * fractol->color + 100) * color;     // Sky Blue
    // fractol->ch[fractol->index + 1] = (fractol->iter * fractol->color + 200) * color; // Sunflower Yellow
    // fractol->ch[fractol->index + 2] = (fractol->iter * fractol->color + 150) * color; // Soft Green
    // fractol->ch[fractol->index + 3] = (fractol->iter * fractol->color + 250) * color; // Pink
    // fractol->ch[fractol->index + 4] = (fractol->iter * fractol->color + 50) * color;  // Lavender
    // fractol->ch[fractol->index + 5] = (fractol->iter * fractol->color + 200) * color; // Pastel Orange
    // fractol->ch[fractol->index + 6] = (fractol->iter * fractol->color + 100) * color; // Light Coral
    // fractol->ch[fractol->index + 7] = 0; // Transparent
    
    //dark ghost
    fractol->index = (4 * 1000 * fractol->y_y) + fractol->x_x * 4;
    fractol->ch[fractol->index] = (fractol->iter * fractol->color + 200) * color;   // Red component (light grey)
    fractol->ch[fractol->index + 1] = (fractol->iter * fractol->color + 200) * color; // Green component (light grey)
    fractol->ch[fractol->index + 2] = (fractol->iter * fractol->color + 200) * color; // Blue component (light grey)
    fractol->ch[fractol->index + 3] = (fractol->iter * fractol->color + 150) * color; // Red component (light blue)
    fractol->ch[fractol->index + 4] = (fractol->iter * fractol->color + 220) * color; // Green component (light blue)
    fractol->ch[fractol->index + 5] = (fractol->iter * fractol->color + 255) * color; // Blue component (light blue)
    fractol->ch[fractol->index + 6] = (fractol->iter * fractol->color + 255) * color; // Red component (white)
    fractol->ch[fractol->index + 7] = (fractol->iter * fractol->color + 255) * color; // Green component (white)
    
    // //my world
    // fractol->index = (4 * 1000 * fractol->y_y) + fractol->x_x * 4;
    // fractol->ch[fractol->index] = (fractol->iter * fractol->color + 14) * color;   // Red component (light grey)
    // fractol->ch[fractol->index + 1] = (fractol->iter * fractol->color + 28) * color; // Green component (light grey)
    // fractol->ch[fractol->index + 2] = (fractol->iter * fractol->color + 42) * color; // Blue component (light grey with blueish tone)
    // fractol->ch[fractol->index + 3] = (fractol->iter * fractol->color + 56) * color; // Red component (light blue)
    // fractol->ch[fractol->index + 4] = (fractol->iter * fractol->color + 70) * color; // Green component (light blue)
    // fractol->ch[fractol->index + 5] = (fractol->iter * fractol->color + 84) * color; // Blue component (light blue)
    // fractol->ch[fractol->index + 6] = (fractol->iter * fractol->color + 98) * color; // Red component (white)
    // fractol->ch[fractol->index + 7] = 0;

    /*fractol->index = (4 * 1000 * fractol->y_y) + fractol->x_x * 4;
    fractol->ch[fractol->index] = (fractol->iter * fractol->color + 255) * color;   // Red component
    fractol->ch[fractol->index + 1] = (fractol->iter * fractol->color + 192) * color; // Green component
    fractol->ch[fractol->index + 2] = (fractol->iter * fractol->color + 203) * color; // Blue component
    fractol->ch[fractol->index + 7] = 0; // Transparent*/


}
