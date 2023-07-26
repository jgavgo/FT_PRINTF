/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:40:29 by jgavilan          #+#    #+#             */
/*   Updated: 2023/07/24 20:43:51 by jgavilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int s, int *count)
{
	if (write(1, &s, 1) == 1) 
		(*count)++;
	else
		*count = -1;
}

void	ft_printwords(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == 6)
		{
			(*count) += 6;
			return ;
		}
		else
		{
			(*count) = -1;
			return ;
		}
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], count);
		if (*count == -1)
			return ;
		i++;
	}
}
