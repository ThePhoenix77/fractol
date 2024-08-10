#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define WIDTH 900
# define HEIGHT 900

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define PINK 0xFFC0CB

# define DBL_MAX_VAL 1.7976931348623157e+308

typedef struct s_cpx
{
	double	r;
	double	i;
}	t_cpx;

typedef struct s_img
{
	void	*p_img;		//mlx_new_image()
	char	*p_pixel;
	int		length;
	int		bit_pixel;
	int		endian;
}	t_img;

typedef struct s_shift
{
	double	x;
	double	y;
}	t_shift;

typedef struct s_direction
{
	double	x_p;
	double	y_p;
	double	x_n;
	double	y_n;
}	t_direction;

typedef struct s_data
{
	char		**argv;
	void		*mlx;		// mlx_init();
	void		*mlx_window;	//mlx_new_window()
	int			axis;
	int			v;
	int			max_it;
	double		z;
	t_cpx		input;
	t_img		img;		//mlx_new_image()
	t_shift		s;
	t_direction	dir;
}	t_data;

int			ft_strcmp(char *s1, char *s2);
int			key_press_action(int k, t_data *data);
int			mouse(int k, int x, int y, t_data *data);
int			on_destroy(t_data *data);
int			arg_size(char *s);
void		my_pixel_put(t_img *img, int x, int y, int color);
void		data_fill(t_data *data, char **av);
void		data_free(t_data *data);
void		drawing(t_data *data);
void		handle_input_error(t_data *data);
void		check_point(char *str, t_data *data);
void		julia(int x, int y, t_data *data);
void		mandelbrot(int x, int y, t_data *data);
void		burning_ship(int x, int y, t_data *data);
void		ft_putstr_fd(char *s, int fd);
void		free_double_pt(char **argv);
void		check_emptiness(char **argv);
void		out_of_bound_dbl(double res);
void		handle_input_error(t_data *data);
double		add_dig(char *str, double res, t_data *data);
double		sttodbl(char *str, t_data *data);
double		to_another_range(double x, double n_rang0,
				double n_rang1, double o_rang);
t_cpx		squar_cpx(t_cpx nb);
t_cpx		small_equa(t_cpx z, t_cpx c);
t_data		*start_fractol(char *name, int argc, char **argv);
t_data		*check_fractol(int argc, char **argv);

#endif
