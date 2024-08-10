#include "../fractol.h"

// Function to map a value 'x' from an original range [0, o_rang] to a new range [n_rang0, n_rang1]
double to_another_range(double x, double n_rang0, double n_rang1, double o_rang)
{
    // Formula to map 'x' from the original range to the new range
    return ((n_rang1 - n_rang0) * x / o_rang + n_rang0);
}

// Function to set the color of a pixel at (x, y) in the image 'img'
void my_pixel_put(t_img *img, int x, int y, int color)
{
    int pos;

    // Calculate the position in the image's pixel array
    pos = (img->length * y) + (x * (img->bit_pixel / 8));

    // Set the pixel at the calculated position to the specified color
    *(int *)(img->p_pixel + pos) = color;
}

// Function to square a complex number 'nb' and return the result
t_cpx squar_cpx(t_cpx nb)
{
    t_cpx res;

    // Real part: (Re(nb))^2 - (Im(nb))^2
    res.r = pow(nb.r, 2) - pow(nb.i, 2);

    // Imaginary part: 2 * Re(nb) * Im(nb)
    res.i = 2 * nb.r * nb.i;

    return (res);
}

// Function to apply the equation z = z^2 + c for complex numbers
t_cpx small_equa(t_cpx z, t_cpx c)
{
    t_cpx res;

    // Square the complex number z
    res = squar_cpx(z);

    // Add the complex number c to the result
    res.r += c.r;
    res.i += c.i;

    return (res);
}

// Function to free a double pointer (array of strings) 'argv'
void free_double_pt(char **argv)
{
    int i;

    i = 0;

    // Check if the pointer is not NULL
    if (argv != NULL)
    {
        // Free each string in the array
        while (argv[i] != NULL)
        {
            free(argv[i]);
            i++;
        }

        // Free the array itself
        free(argv);
    }
}
