#include "../fractol.h"

double	to_another_range(double x, double n_rang0,
				double n_rang1, double o_rang)
{
	return ((n_rang1 - n_rang0) * x / (o_rang) + n_rang0);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	pos;

	pos = (img->length * y) + (x * (img->bit_pixel / 8));
	*(int *)(img->p_pixel + pos) = color;
}

t_cpx	squar_cpx(t_cpx nb)
{
	t_cpx	res;

	res.r = pow(nb.r, 2) - pow(nb.i, 2);
	res.i = 2 * nb.r * nb.i;
	return (res);
}

t_cpx	small_equa(t_cpx z, t_cpx c)
{
	t_cpx	res;

	res = squar_cpx(z);
	res.r += c.r;
	res.i += c.i;
	return (res);
}

void	free_double_pt(char **argv)
{
	int	i;

	i = 0;
	if (argv != NULL)
	{
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}
math_utils.c 
