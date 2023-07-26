#include "shell.h"

/**
 *interactive - this should returns as true if shell is interactive mode
 *@info: struct of the address
 *
 *Return: 1 if mode is  interactive, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *is_delim - checks for this if character is delimeter
 *@c: the defined char to check
 *@delim: the string delimete
 *Return: 1 if returned as true, 0 if returned as false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int m)
{
	if ((m >= 'a' && m <= 'z') || (m >= 'A' && m <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int n, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (n = 0; s[n] != '\0' && flag != 2; n++)
	{
		if (s[n] == '-')
			sign *= -1;

		if (s[n] >= '0' && s[n] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[n] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
