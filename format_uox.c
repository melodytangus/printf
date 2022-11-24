#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * utos - uint to string
 * @str: string
 * @num: num
 *
 * Return: char array
 */
char *utos(char str[], unsigned int num)
{
	int i, rem, len = 0, n;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	i = 0;

	while (i < len)
	{
		rem = num % 10;
		num = num / 10;

		str[len - (i + 1)] = rem + '0';
		i++;
	}

	str[len] = '\0';
	return (str);
}
/**
 * format_u - specificer for unsigned integer
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_u(va_list valist, char *buffer, int *index)
{
	unsigned int i;
	int j, numlen;
	char *num_str;

	i = va_arg(valist, int);
	numlen = num_len(i);
	num_str = malloc(numlen * sizeof(char));
	if (num_str == NULL)
		return;
	utos(num_str, i);
	for (i = *index, j = 0; j < numlen; *index += 1, i++, j++)
	{
		if (*index == 1024)
		{
			_write_string(buffer, index);
			_reset_buffer(buffer);
			*index = 0;
		}
		buffer[*index] = num_str[j];
	}
	free(num_str);
}
/**
 * format_x - specificer for hexadecimal values
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_x(va_list valist, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *hexvalues;
	char *hex;

	n = va_arg(valist, int);
	hexvalues = "0123456789abcdef";
	hex = malloc(9 * sizeof(char));
	if (hex == NULL)
		return;
	for (i = 0; n != 0; i++)
	{
		hex[i] = hexvalues[n % 16];
		n /= 16;
	}
	for (i--; i >= 0; *index += 1, i--)
	{
		buffer[*index] = hex[i];
	}
	free(hex);
}
/**
 * format_X - specificer for ch
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_X(va_list valist, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *hexvalues;
	char *hex;

	n = va_arg(valist, int);
	hexvalues = "0123456789ABCDEF";
	hex = malloc(9 * sizeof(char));
	if (hex == NULL)
		return;
	for (i = 0; n != 0; i++)
	{
		hex[i] = hexvalues[n % 16];
		n /= 16;
	}
	for (i--; i >= 0; *index += 1, i--)
	{
		buffer[*index] = hex[i];
	}
	free(hex);
}
/**
 * format_o - specificer for o
 * @valist: valist
 * @buffer: buffer
 * @index: index
 *
 * Return: void
 */
void format_o(va_list valist, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *octvalues;
	char *oct;

	n = va_arg(valist, int);
	octvalues = "01234567";

	oct = malloc(12 * sizeof(char));
	if (oct == NULL)
		return;
	for (i = 0; n != 0; i++)
	{
		oct[i] = octvalues[n % 8];
		n /= 8;
	}
	for (i--; i >= 0; *index += 1, i--)
	{
		buffer[*index] = oct[i];
	}
	free(oct);
}
