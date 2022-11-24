#include "main.h"
/**
 * num_len - getting the length of a number
 * @num: the number
 *
 * Return: int
 */
int num_len(int num)
{
	int n, len;

	n = num;
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
/**
 * print_int - converts integer to string
 * @str: char array
 * @n: number
 *
 * Return: char array
 */
char *print_int(char *str, long int n)
{
	int i, temp, div, length, last;

	last = n % 10;
	i = 0;
	if (last < 0)
	{
		last *= -1;
		str[i] = '-';
		i++;
	}
	n = (n / 10);
	if (n < 0)
	{
		n *= -1;
	}

	length = 0;
	div = 1;
	temp = n;

	while (temp > 0)
	{
		length += 1;
		div *= 10;
		temp = temp / 10;
	}

	div = div / 10;
	while (div >= 1)
	{
		str[i] = ((n / div) + '0');
		n = n % div;
		div /= 10;
		i++;
	}
	str[i] = last + '0';
	return (str);
}

/**
 * format_d - function that returns an int to signed decimal
 * @valist: arguments passed
 * @buffer: values stored
 * @index: tracks index position
 */
void format_d(va_list valist, char *buffer, int *index)
{
	int i, j, len;
	char *str;

	i = va_arg(valist, int);

	len = num_len(i);
	if (i < 0)
	{
		len += 1;
	}
	str = malloc(len * sizeof(char));
	if (str == NULL)
		return;
	print_int(str, i);
	for (i = *index, j = 0; j < len; *index += 1, i++, j++)
	{
		if (*index == 1024)
		{
			_write_string(buffer, index);
			_reset_buffer(buffer);
			*index = 0;
		}
		buffer[*index] = str[j];
	}
	free(str);
}
