#include "main.h"

 /**
 * strrev - Character to Array
 * @str* Array pointer
 * Return: Array pointer
 **/
char *_strrev (char *str)
{
  int i;
  int len = 0;
  char c;
  if (!str)
    return NULL;
  while(str[len] != '\0'){
    len++;
  }
  for(i = 0; i < (len/2); i++)
  {
    c = str[i];
    str [i] = str[len - i - 1];
    str[len - i - 1] = c;
  }
  return str;
}
/**
 * _itoa - Character to Array
 * @strout: Array pointer
 * @base: Base of number
 * Return: Array pointer
 **/
char * _itoa(int i, char *strout, int base)
{
  char *str = strout;
  int digit, sign = 0;
  if (i < 0) {
    sign = 1;
    i *= -1;
  }
  while(i) {
    digit = i % base;
    *str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
    i = i / base;
    str ++;
  }
  if(sign) {
  *str++ = '-';
  }
  *str = '\0';
  _strrev(strout);
  return strout;
}

/**
 * _printf - Print based on format specifier
 * @format : Specifier argument
 * Return: word count
 **/

int _printf(const char *format, ...)
{
	va_list vl;
	int i = 0, j = 0;
	char buff[1024] = {0}, *format_arg, tmp[1024];

	va_start(vl, format);
	if (!format)
		return (-1);
	while (format && format[i])
	{
	if (format[i] == '%')
	{
		i++;
		switch (format[i])
		{
	/* Convert char */
			case 'c': {
				buff[j] = (char)va_arg(vl, int);
				j++;
			break;
			}
	/* copy formating */
			case 's': {
				format_arg = va_arg(vl, char*);
				strcpy(&buff[j], format_arg);
				j += strlen(format_arg);
			break;
		}
	/* Convert decimal */
			case 'd': {
				_itoa(va_arg( vl, int ), tmp, 10);
				strcpy(&buff[j], tmp);
				j += strlen(tmp);
			break;
			}
		}
	}
	else
		buff[j++] = format[i];
	i++;
	}
	fwrite(buff, j, 1, stdout);
	va_end(vl);
	return (j);
}
