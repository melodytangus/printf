#ifndef PRINTF
#define PRINTF

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
/**
* struct convert - defines a structure for symbols and functions
*
* @ch: The operator
* @f: The function associated
*/
typedef struct convert
{
	char ch;
	void (*f)();
} Scon;

int _printf(const char *format, ...);
int _putchar(char);
void _reset_buffer(char *buffer);
void _write_string(char *buffer, int *index);
void format_s(va_list valist, char *buffer, int *index);
void format_c(va_list valist, char *buffer, int *index);
void format_perc(va_list valist, char *buffer, int *index);
void format_d(va_list valist, char *buffer, int *index);
char *print_int(char *str, long int n);
int num_len(int num);
void format_b(va_list valist, char *buffer, int *index);
void format_u(va_list valist, char *buffer, int *index);
void format_x(va_list valist, char *buffer, int *index);
void format_X(va_list valist, char *buffer, int *index);
void format_o(va_list valist, char *buffer, int *index);
char *utos(char str[], unsigned int num);
void format_p(va_list valist, char *buffer, int *index);
void format_lx(va_list valist, char *buffer, int *index);
void format_rev(va_list valist, char *buffer, int *index);
void format_R(va_list valist, char *buffer, int *index);
#endif
