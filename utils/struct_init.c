#include "../fractol.h"

// Function to compare two strings, returning 0 if they are identical
int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    // Loop through both strings, comparing characters
    while (s1[i] || s2[i])
    {
        // If characters differ, return the difference
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    // If strings are identical, return 0
    return (0);
}

// Function to free allocated data and exit the program
void data_free(t_data *data)
{
    free(data->mlx);  // Free the MLX instance
    free(data);       // Free the main data structure
    exit(1);          // Exit with status 1 (indicating an error)
}

// Function to fill the 'data' structure with initial values and handle errors
void data_fill(t_data *data, char **argv)
{
    // Retrieve image pixel data and handle any errors
    data->img.p_pixel = mlx_get_data_addr(data->img.p_img,
            &data->img.bit_pixel, &data->img.length, &data->img.endian);
    if (!data->img.p_pixel)
    {
        perror("erreur: getting mlx data address has failed !");
        mlx_destroy_image(data->mlx, data->img.p_img);
        mlx_destroy_window(data->mlx, data->mlx_window);
        data_free(data);
    }

    // Initialize other fields in the 'data' structure
    data->argv = argv;
    data->axis = 4;      // Initial value for axis limit
    data->max_it = 42;   // Initial maximum iterations
    data->z = 1;         // Initial zoom level
    data->s.x = 0;       // Initial x-axis shift
    data->s.y = 0;       // Initial y-axis shift
    data->dir.x_p = 2;   // Initial positive x direction boundary
    data->dir.y_p = 2;   // Initial positive y direction boundary
    data->dir.x_n = -2;  // Initial negative x direction boundary
    data->dir.y_n = -2;  // Initial negative y direction boundary
}

// Function to initialize and start the fractal program
t_data *start_fractol(char *name, int argc, char **argv)
{
    t_data *data;

    // Allocate memory for the main data structure
    data = malloc(sizeof(t_data));
    if (!data)
        (perror("erreur: malloc has failed !"), exit(1));

    // If Julia fractal, convert the additional input arguments to double
    if (argc == 4)
    {
        data->input.r = sttodbl(argv[2], data);
        data->input.i = sttodbl(argv[3], data);
    }

    // Initialize the MLX instance
    data->mlx = mlx_init();
    if (!data->mlx)
        (perror("erreur: mlx initiation has failed !"), exit(1));

    // Create a new window for the fractal display
    data->mlx_window = mlx_new_window(data->mlx, WIDTH, HEIGHT, name);
    if (!data->mlx_window)
        (perror("erreur: mlx window creation has failed !"), data_free(data));

    // Create a new image to draw the fractal
    data->img.p_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    if (!data->img.p_img)
    {
        (perror("erreur:img"), mlx_destroy_image(data->mlx, data->mlx_window));
        data_free(data);
    }

    // Fill in the data structure with additional initial values
    data_fill(data, argv);

    return (data);
}

// Function to check the input arguments and start the corresponding fractal
t_data *check_fractol(int argc, char **argv)
{
    t_data *data;

    // Check if the user requested a Julia set with valid input
    if (argc == 4 && !ft_strcmp(argv[1], "julia"))
    {
        check_emptiness(argv);  // Ensure the inputs are not empty
        data = start_fractol("julia", argc, argv);  // Start Julia fractal
        data->v = 3;  // Set fractal type to Julia
    }
    // Check if the user requested the Burning Ship fractal
    else if (argc == 2 && !ft_strcmp(argv[1], "burning_ship"))
    {
        data = start_fractol("burning_ship", argc, argv);  // Start Burning Ship fractal
        data->v = 2;  // Set fractal type to Burning Ship
    }
    // Check if the user requested the Mandelbrot set
    else if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
    {
        data = start_fractol("mandelbrot", argc, argv);  // Start Mandelbrot fractal
        data->v = 1;  // Set fractal type to Mandelbrot
    }
    // If the input is invalid, display an error message and exit
    else
    {
        ft_putstr_fd("CHOOSE ONE OF:\n./fractol (1 / 2 / 3)  ----> \n", 1);
        ft_putstr_fd("1:mandelbrot\n2:burning_ship\n3:julia r i\n", 1);
        exit(1);
    }

    return (data);
}
