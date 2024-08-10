#include "fractol.h"

// Function to draw the fractal based on the selected type (Mandelbrot, Julia, Burning Ship)
void drawing(t_data *data)
{
    int i;
    int j;

    i = 0;
    // Iterate over each pixel column (x-coordinate)
    while (i < WIDTH)
    {
        j = 0;
        // Iterate over each pixel row (y-coordinate)
        while (j < HEIGHT)
        {
            // Check the fractal type and call the corresponding function
            if (data->v == 3)
                julia(i, j, data);          // Draw Julia set
            else if (data->v == 2)
                burning_ship(i, j, data);   // Draw Burning Ship fractal
            else if (data->v == 1)
                mandelbrot(i, j, data);     // Draw Mandelbrot set
            j++;  // Move to the next row
        }
        i++;  // Move to the next column
    }
    // Display the image in the window
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->img.p_img, 0, 0);
}

// Function to handle key press events
int key_press_action(int k, t_data *data)
{
    if (k == 53)  // If the 'ESC' key is pressed
    {
        // Clean up and exit
        mlx_destroy_image(data->mlx, data->img.p_img);
        mlx_destroy_window(data->mlx, data->mlx_window);
        free(data);
        exit(0);
    }
    else if (k == 124)  // Right arrow key
        data->s.x += 0.05 * (data->dir.x_p - data->dir.x_n); // Move view right
    else if (k == 123)  // Left arrow key
        data->s.x -= 0.05 * (data->dir.x_p - data->dir.x_n); // Move view left
    else if (k == 125)  // Down arrow key
        data->s.y -= 0.05 * (data->dir.y_p - data->dir.y_n); // Move view down
    else if (k == 126)  // Up arrow key
        data->s.y += 0.05 * (data->dir.y_p - data->dir.y_n); // Move view up
    else if (k == 78)   // '-' key
        data->max_it -= 10; // Decrease the maximum number of iterations
    else if (k == 69)   // '+' key
        data->max_it += 10; // Increase the maximum number of iterations
    else
        return (0);  // Return if no valid key is pressed
    drawing(data);  // Redraw the fractal with updated parameters
    return (0);
}

// Function to handle mouse events
int mouse(int k, int x, int y, t_data *data)
{
    double x_map;
    double y_map;

    // Map the mouse coordinates to the fractal coordinate space
    x_map = to_another_range(x, data->dir.x_n, data->dir.x_p, WIDTH);
    y_map = to_another_range(y, data->dir.y_p, data->dir.y_n, HEIGHT);
    
    if (k == 4)  // Mouse scroll up (zoom in)
    {
        data->z = 0.9;
    }
    else if (k == 5)  // Mouse scroll down (zoom out)
    {
        data->z = 1.1;
    }
    else
        return (0);  // Return if no valid mouse action is detected
    
    // Adjust the view based on zoom and mouse position
    data->dir.x_p = x_map + (data->dir.x_p - x_map) * data->z;
    data->dir.x_n = x_map + (data->dir.x_n - x_map) * data->z;
    data->dir.y_p = y_map + (data->dir.y_p - y_map) * data->z;
    data->dir.y_n = y_map + (data->dir.y_n - y_map) * data->z;
    
    drawing(data);  // Redraw the fractal with updated parameters
    return (0);
}

// Function to handle window close events
int on_destroy(t_data *data)
{
    // Clean up and exit
    mlx_destroy_image(data->mlx, data->img.p_img);
    mlx_destroy_window(data->mlx, data->mlx_window);
    free(data);
    exit(0);
}

// Main function
int main(int argc, char **argv)
{
    t_data *data;

    // Initialize the fractal data based on command line arguments
    data = check_fractol(argc, argv);
    
    drawing(data);  // Draw the initial fractal
    
    // Set up hooks for user interaction
    mlx_key_hook(data->mlx_window, key_press_action, data);   // Hook for key press events
    mlx_mouse_hook(data->mlx_window, mouse, data);            // Hook for mouse events
    mlx_hook(data->mlx_window, 17, 0, on_destroy, data);      // Hook for window close events
    mlx_loop(data->mlx);  // Start the event loop
    return (0);
}
