/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snowflake <hrychkatetiana@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:13:06 by snowflake         #+#    #+#             */
/*   Updated: 2024/09/20 11:09:15 by snowflake        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#include <stdarg.h>
#include <stdlib.h>

void    my_printf(const char* format, ...)
{
    va_list ptr;

    va_start(ptr, format);

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++; // Move to the specifier after '%'
            switch (format[i])
            {
                case 'c': {
                    char c = (char) va_arg(ptr, int);
                    ft_putchar(c);
                    break;
                }

                case 's': {
                    char *s = va_arg(ptr, char*);
                    int j = 0;
                    while (s[j] != '\0')
                        ft_putchar(s[j++]);
                    break;
                }

                case 'd': {
                    int res = va_arg(ptr, int);
                    ft_putnbr(res);
                    break;
                }

                case 'x': {
                    int n = va_arg(ptr, int);
                    char *str = ft_decimal(n);  // Преобразуем число в шестнадцатеричный формат
                    if (str) {
                        ft_putstr(str);  // Выводим строку
                        free(str);  // Освобождаем память
                    }
                    break;
                }

                case 'X': {
                    int n = va_arg(ptr, int);
                    char *str = ft_decimal(n);
                    if(str) {
                        ft_putstr(strtoupper(str));
                        free(str);
                    }
                    break;
                }

                default: {
                    ft_putchar(format[i]); // Handle unsupported format specifiers
                    break;
                }
            }
        } 
        else 
        {
            ft_putchar(format[i]); // Print regular characters
        }
    }

    va_end(ptr);
}


int main()
{
	//printf("hello my name is %s and i'm %x years old\n", "Laura", 2562);
    my_printf("hello my name is %s and i'm %X years old\n", "Laura", 2562);
    return (0);
}