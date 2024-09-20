/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snowflake <hrychkatetiana@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:52:43 by snowflake         #+#    #+#             */
/*   Updated: 2024/09/20 11:37:22 by snowflake        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb) {

	if (nb > 10)
	{
		ft_putnbr(nb / 10);
	}

	nb %= 10;
	ft_putchar(nb + 48);
}

void	ft_putstr(char *c)
{
	int i;

	i = 0;
	while(c[i])
		ft_putchar(c[i++]);
}

void	ft_reverse(char* str) {

    int first = 0;
    int last = strlen(str) - 1;
    char temp;

    while (first < last) {
      
        temp = str[first];
        str[first] = str[last];
        str[last] = temp;

        first++;
        last--;
    }
}

char *ft_decimal(int i)
{
    int j = 0;
    int remainder;
    char *res = (char *)malloc(10 * sizeof(char)); // Выделяем память

    if (!res)
        return NULL;

    if (i == 0)
    {
        res[j++] = '0';
    }

    while (i > 0)
    {
        remainder = i % 16;  // Остаток от деления на 16
        if (remainder < 10)
            res[j++] = '0' + remainder;  // Для цифр 0-9
        else
            res[j++] = 'a' + (remainder - 10);  // Для символов a-f
        i /= 16;
    }

    res[j] = '\0';  // Добавляем завершающий нуль-символ
    ft_reverse(res);  // Обратный порядок символов
    return res;
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return(c - 32);
	return (c);
}

char* strtoupper(char* s) {

  char* p = s;
  while (*p != '\0') {
    *p = ft_toupper(*p);
    p++;
  }

  return s;
}
