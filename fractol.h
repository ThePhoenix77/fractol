#ifndef FRACTOL_H
# define FRACTOL_H

// Include standard libraries and MLX (MiniLibX) for graphics
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

// Define constants for window dimensions
# define WIDTH 900
# define HEIGHT 900

// Define color constants in hexadecimal format
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define PINK 0xFFC0CB

// Define the maximum value for a double (used in precision checks)
# define DBL_MAX_VAL 1.7976931348623157e+308

// Structure to represent a complex number
typedef struct s_cpx
{
	double	r;  // Real part
	double	i;  // Imaginary part
}	t_cpx;

// Structure to store image data for rendering
typedef struct s_img
{
	void	*p_img;     // Pointer to the image created by mlx_new_image()
	char	*p_pixel;   // Pixel data (address returned by mlx_get_data_addr())
	int		length;     // Length of the image line in bytes
	int		bit_pixel;  // Number of bits per pixel
	int		endian;     // Endianess (0 for little endian, 1 for big endian)
}	t_img;

// Structure to represent a shift in the x and y directions (used for moving the view)
typedef struct s_shift
{
	double	x;  // Shift along the x-axis
	double	y;  // Shift along the y-axis
}	t_shift;

// Structure to represent the current visible range (direction) of the fractal
typedef struct s_direction
{
	double	x_p;  // Positive x direction limit
	double	y_p;  // Positive y direction limit
	double	x_n;  // Negative x direction limit
	double	y_n;  // Negative y direction limit
}	t_direction;

// Main data structure to hold all necessary variables for fractal generation
typedef struct s_data
{
	char		**argv;          // Command-line arguments
	void		*mlx;           // Pointer to the MLX instance (mlx_init())
	void		*mlx_window;    // Pointer to the MLX window (mlx_new_window())
	int			axis;           // Axis flag (not fully defined here)
	int			v;              // Fractal type identifier
	int			max_it;         // Maximum number of iterations for fractal generation
	double		z;              // Zoom factor
	t_cpx		input;          // User input as a complex number
	t_img		img;            // Image data (mlx_new_image())
	t_shift		s;              // Shift data (for panning)
	t_direction	dir;            // Directional boundaries (view window in the fractal space)
}	t_data;

// Function prototypes for the fractol project

// String comparison function (similar to strcmp)
int			ft_strcmp(char *s1, char *s2);

// Key press handler
int			key_press_action(int k, t_data *data);

// Mouse event handler
int			mouse(int k, int x, int y, t_data *data);

// Function to handle window close event (destroy)
int			on_destroy(t_data *data);

// Function to calculate the length of a string
int			arg_size(char *s);

// Function to set a pixel in the image to a specific color
void		my_pixel_put(t_img *img, int x, int y, int color);

// Function to initialize data based on command-line arguments
void		data_fill(t_data *data, char **av);

// Function to free allocated data structures
void		data_free(t_data *data);

// Function to initiate drawing of the fractal
void		drawing(t_data *data);

// Error handling function for invalid input
void		handle_input_error(t_data *data);

// Function to check the validity of a point in the fractal
void		check_point(char *str, t_data *data);

// Functions to draw different types of fractals
void		julia(int x, int y, t_data *data);
void		mandelbrot(int x, int y, t_data *data);
void		burning_ship(int x, int y, t_data *data);

// Function to print a string to a file descriptor
void		ft_putstr_fd(char *s, int fd);

// Function to free a double pointer (array of strings)
void		free_double_pt(char **argv);

// Function to check for empty input arguments
void		check_emptiness(char **argv);

// Function to check if a double value is out of bounds
void		out_of_bound_dbl(double res);

// Another error handling function for invalid input
void		handle_input_error(t_data *data);

// Function to convert a string to a double with error handling
double		add_dig(char *str, double res, t_data *data);

// String to double conversion function with error handling
double		sttodbl(char *str, t_data *data);

// Function to map a value from one range to another
double		to_another_range(double x, double n_rang0,
				double n_rang1, double o_rang);

// Function to square a complex number
t_cpx		squar_cpx(t_cpx nb);

// Function to perform a small equation calculation on complex numbers
t_cpx		small_equa(t_cpx z, t_cpx c);

// Function to start fractal generation based on the provided name and arguments
t_data		*start_fractol(char *name, int argc, char **argv);

// Function to check and validate fractal type and arguments
t_data		*check_fractol(int argc, char **argv);

#endif
