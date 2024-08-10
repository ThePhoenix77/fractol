#include "fractol.h"

// Function to draw a Julia set fractal at pixel (x, y)
void julia(int x, int y, t_data *data)
{
    t_cpx z;         // Complex number z (current point in the fractal space)
    t_cpx c;         // Constant complex number c (defines the specific Julia set)
    int i;           // Iteration counter
    int color;       // Color of the pixel to be drawn

    // Set the constant c from the user input
    c.r = data->input.r;  // Real part of c
    c.i = data->input.i;  // Imaginary part of c

    i = 0;

    // Map the pixel (x, y) to the corresponding complex number z in the fractal space
    z.r = to_another_range(x, data->dir.x_n, data->dir.x_p, WIDTH) + data->s.x;
    z.i = to_another_range(y, data->dir.y_p, data->dir.y_n, HEIGHT) + data->s.y;

    // Iterate to determine if the point (x, y) belongs to the Julia set
    while (i < data->max_it)
    {
        z = small_equa(z, c);  // Apply the Julia set equation: z = z^2 + c

        // Check if the magnitude of z exceeds the escape radius (data->axis)
        if ((pow(z.r, 2) + pow(z.i, 2)) > data->axis)
        {
            // Map the iteration count to a color gradient and set the pixel color
            color = to_another_range(i, BLACK, YELLOW, data->max_it);
            my_pixel_put(&data->img, x, y, color);
            return;  // Exit if the point escapes
        }
        i++;  // Increment the iteration count
    }

    // If the point does not escape within the max iterations, set the pixel to BLACK
    my_pixel_put(&data->img, x, y, BLACK);
}
