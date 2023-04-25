#include "main.h"

/**
 * get_flags - a function that calculates active flags
 * @format: string that tells printf how to format the output
 * @i: pointer to the current index
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_ind;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_ind = *i + 1; format[curr_ind] != '\0'; curr_ind++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_ind] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_ind - 1;

	return (flags);
}
