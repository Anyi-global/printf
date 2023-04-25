#include "main.h"

/**
 * get_width - a function that calculates the width for printing
 * @format: string that tells the printf how to format the output
 * @i: arguments to be printed
 * @args: list of arguments.
 *
 * Return: returns the width of the formatted output
 */
int get_width(const char *format, int *i, va_list args)
{
	int curr_ind;
	int width = 0;

	for (curr_ind = *i + 1; format[curr_ind] != '\0'; curr_ind++)
	{
		if (is_digit(format[curr_ind]))
		{
			width *= 10;
			width += format[curr_ind] - '0';
		}
		else if (format[curr_ind] == '*')
		{
			curr_ind++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = curr_ind - 1;

	return (width);
}
