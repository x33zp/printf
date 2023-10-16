#include "main.h"

/**
 * _printf - A function that prints formated string.
 * @format: is the format specifier.
 * Return: an integer.
 */

int _printf(const char *format, ...)
{
	int char_print = 0;
	va_list args;

	if (format == NULL)
		return(-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_print++;
		}
		else
		{
			format++; 
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				char_print++;

			}
			else if (*format == 'C')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				char_print++;
			}
			else if (*format == 'S')
			{
				char *str = va_arg(args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				write (1, str, str_len);
				char_print += str_len;
			}
                }

		format++;
	}

	va_end(args);

	return char_print;
}
