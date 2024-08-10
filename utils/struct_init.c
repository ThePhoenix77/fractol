#include "../fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	data_free(t_data *data)
{
	free(data->mlx);
	free(data);
	exit(1);
}

void	data_fill(t_data *data, char **argv)
{
	data->img.p_pixel = mlx_get_data_addr(data->img.p_img,
			&data->img.bit_pixel, &data->img.length, &data->img.endian);
	if (!data->img.p_pixel)
	{
		perror("erreur: getting mlx data address has failed !");
		mlx_destroy_image(data->mlx, data->img.p_img);
		mlx_destroy_window(data->mlx, data->mlx_window);
		data_free(data);
	}
	data->argv = argv;
	data->axis = 4;
	data->max_it = 42;
	data->z = 1;
	data->s.x = 0;
	data->s.y = 0;
	data->dir.x_p = 2;
	data->dir.y_p = 2;
	data->dir.x_n = -2;
	data->dir.y_n = -2;
}

t_data	*start_fractol(char *name, int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		(perror("erreur: malloc has failed !"), exit(1));
	if (argc == 4)
	{
		data->input.r = sttodbl(argv[2], data);
		data->input.i = sttodbl(argv[3], data);
	}
	data->mlx = mlx_init();
	if (!data->mlx)
		(perror("erreur: mlx initiation has failed !"), exit(1));
	data->mlx_window = mlx_new_window(data->mlx, WIDTH, HEIGHT, name);
	if (!data->mlx_window)
		(perror("erreur: mlx window creation has failed !"), data_free(data));
	data->img.p_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.p_img)
	{
		(perror("erreur:img"), mlx_destroy_image(data->mlx, data->mlx_window));
		data_free(data);
	}
	data_fill(data, argv);
	return (data);
}

t_data	*check_fractol(int argc, char **argv)
{
	t_data	*data;

	if (argc == 4 && !ft_strcmp(argv[1], "julia"))
	{
		check_emptiness(argv);
		data = start_fractol("julia", argc, argv);
		data->v = 3;
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "burning_ship"))
	{
		data = start_fractol("burning_ship", argc, argv);
		data->v = 2;
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
	{
		data = start_fractol("mandelbrot", argc, argv);
		data->v = 1;
	}
	else
	{
		ft_putstr_fd("CHOOSE ONE OF:\n./fractol (1 / 2 / 3)  ----> \n", 1);
		ft_putstr_fd("1:mandelbrot\n2:burning_ship\n3:julia r i\n", 1);
		exit(1);
	}
	return (data);
}
