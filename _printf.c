#include "main.h"
/**
  * _printf - function that prints based on format specifier
  * @format: takes in format specifier
  * Return: return pointer to index
  */
int _printf(const char *format, ...)
{
	char buffer[1024];
	int i, j = 0, a = 0, *index = &a;
	va_list valist;
	Scon specifier[] = {
		{'c', format_c}, {'s', format_s}, {'%', format_perc},
		{'d', format_d}, {'i', format_d}, {'b', format_b}, {'\0', NULL},
		{'u', format_u}, {'x', format_x}, {'X', format_X}, {'o', format_o},
		{'p', format_p}, {'r', format_rev}, {'R', format_R}, {'\0', NULL},
	};
	if (!format)
		return (-1);
	va_start(valist, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		for (; format[i] != '%' && format[i] != '\0'; *index += 1, i++)
		{
			if (*index == 1024)
			{	_write_string(buffer, index);
				_reset_buffer(buffer);
				*index = 0;
			}
			buffer[*index] = format[i];
		}
		if (format[i] == '\0')
			break;
		if (format[i] == '%')
		{	i++;
			for (j = 0; specifier[j].ch != '\0'; j++)
			{
				if (format[i] == specifier[j].ch)
				{	specifier[j].f(valist, buffer, index);
					break;
				}
			}
		}
	}
	va_end(valist);
	buffer[*index] = '\0';
	_write_string(buffer, index);
	return (*index);
}
