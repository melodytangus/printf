#include "main.h"
/**
 * format_b - function to convert to unsigned integer to binary
 * @valist: taking in arguments
 * @buffer: values stored
 * @index: tracks the index position
 */
void format_b(va_list valist, char *buffer, int *index)
{
	unsigned int number;
	int i;
	char *binaryvalues;
	char *binary;

	number = va_arg(valist, int);
	binaryvalues = "01";
	binary = malloc(sizeof(char) * 33);
	if (binary == NULL)
		return;
	if (number == 0)
	{
		buffer[*index] = '0';
		*index += 1;
	}
	else
	{
		for (i = 0; number != 0; i++)
		{
			binary[i] = binaryvalues[number % 2];
			number /= 2;
		}
		for (i--; i >= 0; *index += 1, i--)
		{
			buffer[*index] = binary[i];
		}
	}
	free(binary);
}
