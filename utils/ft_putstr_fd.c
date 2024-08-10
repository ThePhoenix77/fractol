#include "../fractol.h"

// Function to write a string 's' to a file descriptor 'fd'
void ft_putstr_fd(char *s, int fd)
{
    // Check if the file descriptor is invalid or if the string is NULL
    if ((fd < 0) || (!s))
        return;

    // Loop through each character in the string and write it to 'fd'
    while (*s != '\0')
    {
        write(fd, s, 1);  // Write the current character to the file descriptor
        s++;  // Move to the next character in the string
    }
}

// Function to determine the length of a string 's'
int arg_size(char *s)
{
    int i;

    i = 0;
    // Loop until the end of the string (when s[i] is '\0')
    while (s[i])
        i++;
    return (i);  // Return the length of the string
}

// Function to check if the third and fourth arguments (argv[2] and argv[3]) are empty
void check_emptiness(char **argv)
{
    // If either argument is an empty string (length 0), print an error message and exit
    if (arg_size(argv[2]) == 0 || arg_size(argv[3]) == 0)
    {
        ft_putstr_fd("erreur: julia empty values !\n", 1);  // Print error message to stdout
        exit(1);  // Exit the program with status 1 (indicating an error)
    }
}
