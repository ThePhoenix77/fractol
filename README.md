# fractol: Fractal Visualization with C and MLX
This project, fractol, is a fractal visualization program written in C using the MiniLibX (MLX) library.

## What are Fractals?
Fractals are self-similar mathematical objects exhibiting intricate patterns that repeat at different scales. They often possess beauty and complexity arising from relatively simple rules or equations.

## Project Overview
fractol allows you to explore various fractal sets by generating corresponding images. The program currently supports the implementation of the following classic fractals:

  *  Mandelbrot Set: One of the most well-known fractals, famous for its intricate details and mesmerizing shapes.
  *  Julia Set: A related fractal family with unique features depending on the chosen complex parameter c.
  *  Burning Ship Set: Another intriguing fractal set characterized by its distinctive "flaming ship" appearance.


## Implementation Details
The program utilizes the MLX library for low-level graphics manipulation. This allows for:

  *  Creating a graphical window to display the generated fractal images.
  *  Performing pixel-level manipulation to render the different fractal sets.
  *  Handling user interaction for features such as zooming and color palette selection.

## Getting Started
### Prerequisites:
  *  C Compiler (e.g., GCC)
  *  MiniLibX library (MLX)
### Instructions:

  *  Clone this repository: git clone https://github.com/ThePhoenix77/fractol.git
  *  Install the necessary libraries. [MLX documentation](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html).
  *  Compile the program: gcc fractol.c -lmlx -lX11 -lm -o fractol (modify flags if needed)
  *  Run the program: ./fractol

### Controls:

  *  Arrow keys: Navigate within the fractal space (zooming).
  *  Mouse wheel: Zoom in/out on the fractal.
  *  Escape key: Exit the program.

## Customization:

This initial version focuses on core functionality. You can explore potential improvements:

  *  Implement additional fractal sets.
  *  Introduce color palettes for different fractal sets.
  *  Add user interface elements for customization options.

## Contributing
I welcome contributions to this project! Please refer to the CONTRIBUTING.md file (if included) for guidelines on submitting pull requests.

This README provides a basic understanding of the fractol project. Feel free to explore the code and experiment with different functionalities!
