#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/*
 * File - main.h
 * Author - zubby peculiar
 * Description: A header file containg functions used in
 * 		the printf project.
 */

int _printf(const char *format, ...);
int _pchar(char a);
int _myput(char *str);
int print_number(int n);

#endif
