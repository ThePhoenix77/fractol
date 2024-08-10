#include "../fractol.h"

// Function to check if a double value is within the valid range of a double
void out_of_bound_dbl(double res)
{
    // Check if the result exceeds the maximum or minimum double value
    if (-DBL_MAX_VAL > res || res > DBL_MAX_VAL)
    {
        ft_putstr_fd("erreur: out of bound !", 1);  // Print error message to stdout
        exit(1);  // Exit the program with status 1 (indicating an error)
    }
}

// Function to validate the format of a string representing a floating-point number
void check_point(char *str, t_data *data)
{
    int i;
    int pt_count;

    i = 0;
    pt_count = 0;

    // Check if the string starts with a decimal point (invalid format)
    if (str[0] == '.')
        handle_input_error(data);

    // Iterate through the string to count the number of decimal points
    while (str[i])
    {
        if (str[i] == '.')
            pt_count++;
        i++;
    }

    // If there are more than one decimal point, the format is invalid
    if (pt_count >= 2)
        handle_input_error(data);
}

// Function to handle the fractional part of a string representing a floating-point number
double add_dig(char *str, double res, t_data *data)
{
    int i;
    double a;

    a = 0.1;  // Start with the first decimal place (tenths)
    i = 0;

    // Iterate through each digit after the decimal point
    while (str[i] >= '0' && str[i] <= '9')
    {
        res += (str[i] - '0') * a;  // Add the digit multiplied by the current decimal place value
        a *= 0.1;  // Move to the next decimal place (e.g., hundredths)
        i++;
    }

    // If there are non-digit characters remaining, the format is invalid
    if (str[i] != '\0')
        handle_input_error(data);

    return (res);  // Return the updated result with the fractional part added
}

// Function to convert a string to a double, with error handling
double sttodbl(char *str, t_data *data)
{
    int i;
    int s;      // Sign of the number (positive or negative)
    double res; // Resulting double value

    i = 0;
    s = 1;     // Default sign is positive
    res = 0;

    check_point(str, data);  // Validate the format of the string

    // Check for an optional sign at the beginning of the string
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            s *= -1;  // If the sign is negative, change the sign multiplier
        i++;
    }

    // Convert the integer part of the string to a double
    while (str[i] >= '0' && str[i] <= '9')
    {
        out_of_bound_dbl(res * 10 + (str[i] - '0'));  // Check for overflow/underflow
        res = res * 10 + (str[i] - '0');  // Update the result
        i++;
    }

    // If the string ends here, return the result
    if (str[i] == '\0')
        return (s * res);

    // If the next character is not a decimal point, the format is invalid
    else if (str[i] != '.')
        handle_input_error(data);

    // Handle the fractional part if present
    return (s * add_dig(&str[i + 1], res, data));
}
