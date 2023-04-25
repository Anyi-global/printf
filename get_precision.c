#include "main.h"

/**
 * get_precision - a function that calculates the precision for printing
 * @format: string that tells printf how to format the output
 * @i: arguments to be printed.
 * @args: list of arguments.
 *
 * Return: returns the precision of the output
 */
int get_precision(const char *format, int *i, va_list args)
{
	int curr_ind = *i + 1;
	int precision = -1;

	if (format[curr_ind] != '.')
		return (precision);

	precision = 0;

	for (curr_ind += 1; format[curr_ind] != '\0'; curr_ind++)
	{
		if (is_digit(format[curr_ind]))
		{
			precision *= 10;
			precision += format[curr_ind] - '0';
		}
		else if (format[curr_ind] == '*')
		{
			curr_ind++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = curr_ind - 1;
	return (precision);
}
