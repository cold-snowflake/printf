/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snowflake <hrychkatetiana@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:13:06 by snowflake         #+#    #+#             */
/*   Updated: 2024/10/06 19:27:45 by snowflake        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
// Modified my_printf function
int my_printf(const char *format, ...)
{
    va_list ptr;
    int printed_char = 0;

    va_start(ptr, format);
    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                char c = (char)va_arg(ptr, int);
                ft_putchar(c);
                printed_char++;
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(ptr, char *);
                printed_char += ft_putstr(str);
            }
			else if ((format[i] == 'd') || (format[i] == 'i'))
			{
	        	int res = va_arg(ptr, int);
	        	printed_char += ft_putnbr(res);
			}
			else if (format[i] == 'x')
			{
	        	int n = va_arg(ptr, int);
		    	char *str = ft_decimal(n);  // Преобразуем число в шестнадцатеричный формат
            	if (str) 
				{
					ft_putstr(str);  // Выводим строку
               		free(str);
				}
			}
			else if (format[i] == 'X')
			{
	           int n = va_arg(ptr, int);
	           char *str = ft_decimal(n);
	           if(str)
			   {
	               ft_putstr(strtoupper(str));
	               free(str);
            	}
			}
		}
            // You can add more format specifiers here (e.g., %d, %x)
        else
        {
            ft_putchar(format[i]); // Print regular characters
            printed_char++; // Increment for printed character
        }
    }
    va_end(ptr);
    return printed_char; // Return the total count of printed characters
}

int main()
{
	int c = 6565;
    const char *name = "Laura";
    
    printf("hello my name is %s and I'm %x years old\n", name, c);
    my_printf("hello my name is %s and I'm %x years old\n", name, c);
    
    return 0;
}



        //         case 'x': {
        //             int n = va_arg(ptr, int);
        //             char *str = ft_decimal(n);  // Преобразуем число в шестнадцатеричный формат
        //             if (str) {
        //                 ft_putstr(str);  // Выводим строку
        //                 free(str);  // Освобождаем память
        //             }
        //             break;
        //         }

        //         case 'X': {
        //             int n = va_arg(ptr, int);
        //             char *str = ft_decimal(n);
        //             if(str) {
        //                 ft_putstr(strtoupper(str));
        //                 free(str);
        //             }
        //             break;
        //         }

        //         case 'p': {
        //             void* p = va_arg(ptr, void*);
        //             printed_char += ft_putp(p);
        //             break;
        //         }

        //         case 'i': {
        //             int res = va_arg(ptr, int);
        //             ft_putnbr(res);
        //             break;                    
        //         }

        //         case 'u': {
        //             unsigned int res = va_arg(ptr, unsigned int);
        //             ft_putuns_number(res);
        //             break; 
        //         }

        //         default: {
        //             ft_putchar(format[i]); // Handle unsupported format specifiers
        //             break;
        //         }
        //     }
        // } 
//         else 
//         {
//             ft_putchar(format[i]); // Print regular characters
//         }
//     }

//     va_end(ptr);
//     return (printed_char);
// }


