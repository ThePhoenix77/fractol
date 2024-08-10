#include "../fractol.h"

void	handle_input_error(t_data *data)
{
	perror("erreur: not a valid numerical values !");
	free(data);
	exit(1);
}
