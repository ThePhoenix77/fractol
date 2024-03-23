#	ifndef FRACTOL_H
#	define FRACTOL_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

#	define WIDTH 600
#	define HIGHT 600

typedef struct		s_fractol
{
	unsigned char	*ch;
    char			*name;
    void			*ptr;
	void			*win;
    void			*image;
	double			x;
	double			y;
	double			x_x;
	double			y_y;
	double			x_o;
	double			y_o;
	double			xtmp;
	double			ytmp;
    double			start_y;
	double			end_y;
	double			start_x;
	double			end_x;
    int				iter;
	int				size_l;
	int				bpp;
	int				endian;
	int				index;
	int				zoom;
	int				stop;
	int				max;
	int				color;

}					t_fractol;

void				mandelbrot(t_fractol *fractol);
int					ft_strcmp(char *s1, char *s2);
int					mouse_move(int x, int y, t_fractol *fractol);
int					mouse_press(int button, int x, int y, t_fractol *fractol);
int					key_press(int keycode, t_fractol *fractol);
int					key_press(int keycode, t_fractol *fractol);
void				julia(t_fractol *fractol);
void				menu(t_fractol *fractol);
void				iter_loop(t_fractol *fractol);
void				map(t_fractol *fractol);
double				ft_abs(double x);
void				key_press2(int keycode, t_fractol *fractol);
void				key_press3(int keycode, t_fractol *fractol);
void				key_press4(int keycode, t_fractol *fractol);
void				set_color(t_fractol *fractol, int color);
int					str_cmp(char *s1, char *s2);
void				check_ar(t_fractol *fractol);
void				init(t_fractol *fractol, char *str);
void				string_put(t_fractol *fractol);
void				zoom(t_fractol *fractol, double x, double y, double zoom);
void				mlx_ho(t_fractol *fractol);
void				simple_zoome1(t_fractol *fractol);
void				simple_zoome2(t_fractol *fractol);
void				init_x_y(t_fractol *fractol);
void				string1_put(t_fractol *fractol);
void				destroy_exit(t_fractol *fractol);

#	endif
