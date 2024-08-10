#include "../fractol.h"

// Function to display an error msg & exit
void	handle_input_error(t_data *data)
{
	perror("erreur: not a valid numerical values !");
	// Free allocated data and exit the program
	free(data);
	exit(1);
}
