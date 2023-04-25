#include "main.h"

/**
 * get_size - a function that calculates the size to cast the argument
 * @format: string that tells the printf how to format the output
 * @i: arguments to be printed
 *
 * Return: returns the size
 */
int get_size(const char *format, int *i)
{
	int curr_ind = *i + 1;
	int size = 0;

	if (format[curr_ind] == 'l')
		size = S_LONG;
	else if (format[curr_ind] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_ind - 1;
	else
		*i = curr_ind;

	return (size);
}
