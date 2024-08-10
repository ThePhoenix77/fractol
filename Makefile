NAME = fractol

FLAGS = -Wall -Wextra -Werror

F_MLX = -lmlx -framework OpenGL -framework AppKit -O3

SRC = main.c  mandelbrot.c julia.c utils/ft_putstr_fd.c utils/struct_init.c utils/math_utils.c utils/sttodbl.c utils/handle_input_error.c

OBJ = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	cc ${FLAGS} ${OBJ} ${F_MLX} -o ${NAME}

%.o : %.c fractol.h
	cc ${FLAGS} -O3 -c $< -o $@

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all
