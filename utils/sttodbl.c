#include "../fractol.h"

void	out_of_bound_dbl(double res)
{
	if (-DBL_MAX_VAL > res || res > DBL_MAX_VAL)
	{
		ft_putstr_fd("erreur: out of bound !", 1);
		exit(1);
	}
}

void	check_point(char *str, t_data *data)
{
	int	i;
	int	pt_count;

	i = 0;
	pt_count = 0;
	if (str[0] == '.')
		handle_input_error(data);
	while (str[i])
	{
		if (str[i] == '.')
			pt_count++;
		i++;
	}
	if (pt_count >= 2)
		handle_input_error(data);
}

double	add_dig(char *str, double res, t_data *data)
{
	int		i;
	double	a;

	a = 0.1;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res += (str[i] - '0') * a;
		a *= 0.1;
		i++;
	}
	if (str[i] != '\0')
		handle_input_error(data);
	return (res);
}

double	sttodbl(char *str, t_data *data)
{
	int		i;
	int		s;
	double	res;

	i = 0;
	s = 1;
	res = 0;
	check_point(str, data);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out_of_bound_dbl(res * 10 + (str[i] - '0'));
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '\0')
		return (s * res);
	else if (str[i] != '.')
		handle_input_error(data);
	return (s * add_dig(&str[i + 1], res, data));
}
