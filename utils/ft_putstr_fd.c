#include "../fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	if ((fd < 0) || (!s))
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

int	arg_size(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	check_emptiness(char **argv)
{
	if (arg_size(argv[2]) == 0 || arg_size(argv[3]) == 0)
	{
		ft_putstr_fd("erreur: julia empty values !\n", 1);
		exit(1);
	}
}
