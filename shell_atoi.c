#include "shell.h"

/**
 *Convert a string to an integer.
 *@param str The input string.
 *@return The converted integer.
 */
int shell_atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[0] == '+')
	{
		i++;
	}

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		else
		{
			break;
		}

		i++;
	}

	return (sign * result);
}
