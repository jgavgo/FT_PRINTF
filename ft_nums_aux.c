/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:39:04 by jgavilan          #+#    #+#             */
/*   Updated: 2023/07/26 23:10:18 by jgavilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_num(unsigned int num, int *count)
{
	if (num >= 10 && *count != -1)
		ft_unsigned_num(num / 10, count);
	if (*count != -1)
	{
		ft_putchar(num % 10 + '0', count);
		if (*count == -1)
			return ;
	}
}

void	ft_hex_num(unsigned int num, int *count, char str)
{
	char	*base_character;

	if (num >= 16 && *count != -1)
		ft_hex_num(num / 16, count, str);
	if (str == 'X' && *count != -1)
	{
		base_character = "0123456789ABCDEF";
		ft_putchar(base_character[num % 16], count);
		if (*count == -1)
			return ;
	}
	if (str == 'x' && *count != -1)
	{
		base_character = "0123456789abcdef";
		ft_putchar(base_character[num % 16], count);
		if (*count == -1)
			return ;
	}
}

void	ft_head_point(unsigned long point_char, int *count)
{
	ft_printwords("0x", count);
	ft_point_char(point_char, count);
}

void	ft_point_char(unsigned long point_char, int *count)
{
	char	*base_character;

	base_character = "0123456789abcdef";
	if (*count != -1)
	{
		if (point_char >= 16 && *count != -1)
			ft_point_char(point_char / 16, count);
		if (*count != -1)
		{
			ft_putchar(base_character[point_char % 16], count);
			if (*count == -1)
				return ;
		}
	}
}

void	ft_numbers(int num, int *count)
{
	if (num == -2147483648 && *count != -1)
	{
		ft_printwords("-2147483648", count);
		return ;
	}
	if (num < 0 && *count != -1)
	{
		ft_putchar('-', count);
		if (*count == -1)
			return ;
		num *= -1;
	}
	if (num >= 10 && *count != -1)
	{
		ft_numbers(num / 10, count);
		ft_numbers(num % 10, count);
	}
	if (num >= 0 && num <= 9 && *count != -1)
	{
		ft_putchar(num + '0', count);
		if (*count == -1)
			return ;
	}
}
