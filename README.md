# ft_printf
Because putnbr and putstr aren’t enough.

Program name | libftprintf.a
:----------- | :------------
Turn in files    | Makefile, \*.h, \*/\*.h, \*.c, \*/\*.c
Makefile         | NAME, all, clean, fclean, re
External funcs   | malloc, free, write, va_start, va_arg, va_copy, va_end
Libft authorized | Yes

## Requirement
The task is to implement the _ft_printf()_ function that mimics the behavior of the printf() function from the standard C library, with the following requirements:

* The function should handle conversions for the following format specifiers: c, s, p, d, i, u, x, X, %.
* The buffer management of the original printf() function should not be implemented.
* The implementation will be compared against the original printf() function.
* The library must be created using the ar command.
* The library libftprintf.a must be created in the root of the repository.

### Conversion Specifiers
* The following conversion specifiers must be implemented:

	specifier | Output
	:-------: | :----
	%c        | Print a single character.
	%s        | Print a string.
	%p        | Print the value of a void pointer in hexadecimal format.
	%d        | Print a decimal (base 10) integer.
	%i        | Print an integer in base 10.
	%u        | Print an unsigned decimal (base 10) integer.
	%x        | Print a number in hexadecimal (base 16) lowercase format.
	%X        | Print a number in hexadecimal (base 16) uppercase format.
	%%        | Print a percent sign.

## Bonus Requirement
* The function should handle any combination of the following flags: -, 0, and . under all conversions.
* The function should handle all the following flags: #, +, and space.
