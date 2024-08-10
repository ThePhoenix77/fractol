# Name of the executable to be created
NAME = fractol

# Compilation flags: 
# -Wall: Enable all warnings
# -Wextra: Enable extra warnings
# -Werror: Treat warnings as errors
FLAGS = -Wall -Wextra -Werror

# MLX (MiniLibX) flags:
# -lmlx: Link with the MLX library
# -framework OpenGL: Use the OpenGL framework
# -framework AppKit: Use the AppKit framework for MacOS GUI
# -O3: Optimization level 3 for performance
F_MLX = -lmlx -framework OpenGL -framework AppKit -O3

# Source files for the project
SRC = main.c mandelbrot.c julia.c \
      utils/ft_putstr_fd.c utils/struct_init.c \
      utils/math_utils.c utils/sttodbl.c \
      utils/handle_input_error.c

# Object files (generated from the source files)
# ${SRC:.c=.o} converts each .c file in SRC to a corresponding .o file
OBJ = ${SRC:.c=.o}

# Default rule to build the project
all : ${NAME}

# Rule to create the executable from the object files
${NAME} : ${OBJ}
	# Compile and link the object files with the specified flags and MLX options
	cc ${FLAGS} ${OBJ} ${F_MLX} -o ${NAME}

# Rule to create object files (.o) from source files (.c)
# %.o : %.c means that for each .c file there will be a corresponding .o file
%.o : %.c fractol.h
	# Compile the source file into an object file with optimization (-O3)
	cc ${FLAGS} -O3 -c $< -o $@

# Rule to clean up object files
clean :
	# Remove all object files (.o)
	rm -f ${OBJ}

# Rule to clean up object files and the executable
fclean : clean
	# Remove the executable
	rm -f ${NAME}

# Rule to rebuild the project from scratch
re : fclean all
	# Calls 'fclean' to remove all generated files, then 'all' to rebuild
