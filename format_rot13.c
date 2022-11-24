#include "main.h"
/**
 * format_R - functtion that converts a string into rot13
 * @valist: argument passed
 * @buffer: values stored
 * @index: tracks index position
 */
void format_R(va_list valist, char *buffer, int *index)
{
	char *s;
	int i, j;

	char *s1 = "abcdefghijklmABCDEFGHIJKLM ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|.\n";
	char *s2 = "nopqrstuvwxyzNOPQRSTUVWXYZ ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|.\n";

	s = va_arg(valist, char *);
	for (i = 0; s[i] != '\0'; i++, *index += 1)
	{
		for (j = 0; s1[j] != '\0'; j++)
		{
			if (s[i] == s1[j])
			{
				buffer[*index] = s2[j];
			}
			else if (s[i] == s2[j])
			{
				buffer[*index] = s1[j];
			}
		}
	}
}
