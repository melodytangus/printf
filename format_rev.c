#include "main.h"
/**
 * _strlen - count the length of a string
 *  @s: char pointer
 *
 * Return: integer
 */
int _strlen(char *s)
{
	int i, count;

	count = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		count++;
	}
	return (i);
}
/**
 * format_rev - reverse a string passed in
 * @valist: argument passed in
 * @buffer: values stored
 * @index: returns pointer to index
 */
void format_rev(va_list valist, char *buffer, int *index)
{
	int i, strlen;
	char *s;

	s = va_arg(valist, char *);
	strlen = _strlen(s) - 1;

	for (i = strlen; i >= 0; i--, *index += 1)
	{
		buffer[*index] = s[i];
	}
}
