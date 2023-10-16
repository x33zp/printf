#include "main.h"

/**
 * _printf - A function that prints formated string.
 * @format: is the format specifier.
 * @...: Variable number of arguments
 * Return: an integer.
 */

int _printf(const char *format, ...)
{

	va_list list_of_args;
	int i, j, count = 0;
	char cha;

	if (format == NULL)
		return (-1);
	va_start(list_of_args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
			count += _pchar(format[i]);
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			cha = format[i];

			if (cha == 'c')
				count += _pchar(va_arg(list_of_args, int));
			else if (cha == 's')
			{
				char *str = va_arg(list_of_args, char *);

				if (str == NULL)
					str = "(null)";
				for (j = 0; str[j] != '\0'; j++)
					count += _pchar(str[j]);
			}
			else if (cha == 'd' || cha == 'i')
				count += print_number(va_arg(list_of_args, int));
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			count += _pchar('%');
			i++;
		}
	}
	va_end(list_of_args);
	return (count);
}
