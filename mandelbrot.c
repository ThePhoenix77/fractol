#include "fractol.h"

// Function to draw the Mandelbrot set at pixel (x, y)
void mandelbrot(int x, int y, t_data *data)
{
    t_cpx z;      // Complex number z (initially set to 0 + 0i)
    t_cpx c;      // Complex number c (corresponds to the pixel's mapped coordinates)
    int i;        // Iteration counter
    int color;    // Color of the pixel to be drawn

    // Initialize z to the origin (0 + 0i)
    z.r = 0;
    z.i = 0;

    i = 0;

    // Map the pixel (x, y) to the corresponding complex number c in the Mandelbrot space
    c.r = to_another_range(x, data->dir.x_n, data->dir.x_p, WIDTH) + data->s.x;
    c.i = to_another_range(y, data->dir.y_p, data->dir.y_n, HEIGHT) + data->s.y;

    // Iterate to determine if the point (x, y) belongs to the Mandelbrot set
    while (i < data->max_it)
    {
        z = small_equa(z, c);  // Apply the Mandelbrot equation: z = z^2 + c

        // Check if the magnitude of z exceeds the escape radius (data->axis)
        if ((pow(z.r, 2) + pow(z.i, 2)) > data->axis)
        {
            // Map the iteration count to a color gradient and set the pixel color
            color = to_another_range(i, BLACK, PINK, data->max_it);
            my_pixel_put(&data->img, x, y, color);
            return;  // Exit if the point escapes
        }
        i++;  // Increment the iteration count
    }

    // If the point does not escape within the max iterations, set the pixel to BLACK
    my_pixel_put(&data->img, x, y, BLACK);
}

// Function to draw the Burning Ship fractal at pixel (x, y)
void burning_ship(int x, int y, t_data *data)
{
    t_cpx z;      // Complex number z (initially set to 0 + 0i)
    t_cpx c;      // Complex number c (corresponds to the pixel's mapped coordinates)
    int i;        // Iteration counter
    int color;    // Color of the pixel to be drawn

    // Initialize z to the origin (0 + 0i)
    z.r = 0;
    z.i = 0;

    i = 0;

    // Map the pixel (x, y) to the corresponding complex number c in the Burning Ship space
    c.r = to_another_range(x, data->dir.x_n, data->dir.x_p, WIDTH) + data->s.x;
    c.i = to_another_range(y, data->dir.y_p, data->dir.y_n, HEIGHT) + data->s.y;

    // Iterate to determine if the point (x, y) belongs to the Burning Ship fractal
    while (i < data->max_it)
    {
        z = small_equa(z, c);  // Apply the Burning Ship equation: z = z^2 + c

        // Apply the Burning Ship specific transformation (absolute values)
        z.r = fabs(z.r);
        z.i = fabs(z.i);

        // Check if the magnitude of z exceeds the escape radius (data->axis)
        if ((pow(z.r, 2) + pow(z.i, 2)) > data->axis)
        {
            // Map the iteration count to a color gradient and set the pixel color
            color = to_another_range(i, BLACK, PINK, data->max_it);
            my_pixel_put(&data->img, x, y, color);
            return;  // Exit if the point escapes
        }
        i++;  // Increment the iteration count
    }

    // If the point does not escape within the max iterations, set the pixel to BLACK
    my_pixel_put(&data->img, x, y, BLACK);
}
