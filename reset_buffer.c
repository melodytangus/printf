#include "main.h"

/**
 * _reset_buffer - function that initializes and resets a buffer
 * @buffer: buffer size
 * Return: void
 */

void _reset_buffer(char *buffer)
{
int i;

for (i = 0; i < 1024; i++)
{
buffer[i] = 0;
}
buffer[i] = '\0';
}
