/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snowflake <hrychkatetiana@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:52:43 by snowflake         #+#    #+#             */
/*   Updated: 2024/10/06 19:27:28 by snowflake        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int nb)
{
	int res;

	res = 0;
	if (nb < 0)
	{
		res += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		res += ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		res += ft_putchar(nb + 48);
	return (res);
}

void	ft_putuns_number(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	nb %= 10;
	ft_putchar(nb + 48);
}

int	ft_putstr(char	*c)
{
	int	i;

	i = 0;
	while (c[i])
		ft_putchar(c[i++]);
	return (i);
}

void	ft_reverse(char	*str)
{
	int		first;
	int		last;
	char	temp;

	first = 0;
	last = strlen(str) - 1;
	while (first < last)
	{
		temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		first++;
		last--;
	}
}

char	*ft_decimal(size_t	i)
{
	int		j;
	int		remainder;
	char	*res;

	j = 0;
	res = (char *)malloc(10 * sizeof(char));
	if (!res)
		return (NULL);
	if (i == 0)
	{
		res[j++] = '0';
	}
	while (i > 0)
	{
		remainder = i % 16;
		if (remainder < 10)
			res[j++] = '0' + remainder;
		else
			res[j++] = 'a' + (remainder - 10);
		i /= 16;
	}
	res[j] = '\0';
	ft_reverse(res);
	return (res);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	*strtoupper(char	*s)
{
	char	*p;

	p = (char	*)malloc(sizeof(*p) * strlen(s));
	while (*p != '\0')
	{
		*p = ft_toupper(*p);
		p++;
	}
	return (s);
}

int	ft_putp(void *ptr)
{
	int		count;
	char	*hex_str;

	count = 0;
	count += write(1, "0x", 2);
	hex_str = ft_decimal((size_t)ptr);
	if (!hex_str)
		return (-1);
	count += write(1, hex_str, strlen(hex_str));
	free(hex_str);
	return (count);
}
