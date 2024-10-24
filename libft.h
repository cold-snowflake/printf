/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snowflake <hrychkatetiana@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:52:35 by snowflake         #+#    #+#             */
/*   Updated: 2024/10/06 16:31:45 by snowflake        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

int		ft_putchar(char c);
int		ft_putnbr(int nb);
char	*ft_decimal(size_t i);
int		ft_putstr(char *c);
int		ft_toupper(int c);
char	*strtoupper(char *s);
int		ft_putp(void *ptr);
void	ft_putuns_number(unsigned int nb);

#endif