/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:53:21 by jgavilan          #+#    #+#             */
/*   Updated: 2023/07/26 22:58:16 by jgavilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sel_func(char str, va_list args, int *count)
{
	if (str == 'c' && *count != -1)
		ft_putchar(va_arg(args, int), count);
	else if (str == 's' && *count != -1)
		ft_printwords(va_arg(args, char *), count);
	else if ((str == 'i' || str == 'd') && *count != -1)
		ft_numbers(va_arg(args, int), count);
	else if (str == 'p' && *count != -1)
		ft_head_point(va_arg(args, unsigned long), count);
	else if (str == 'u' && *count != -1)
		ft_unsigned_num(va_arg(args, unsigned int), count);
	else if ((str == 'x' || str == 'X') && *count != -1)
		ft_hex_num(va_arg(args, unsigned int), count, str);
	else if (str == '%' && *count != -1)
		ft_putchar('%', count);
	return ;
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			sel_func(str[i + 1], args, &count);
			i++;
		}
		else
			ft_putchar(str[i], &count);
		i++;
		if (count == -1)
			return (count);
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	char			c;
	int				character;
	char			*str;
	int				string;
	unsigned int	valor;
	int				numnum;

	c = 'j';
	valor = -5;
	//(unsigned int)valor;
	numnum = 0;
	str = "HOLA\n";
	character = 0;
	string = 0;
	//printf("Llego aqui\n");
	//printf("%u\n", valor);
	//numnum = ft_printf("%s", (char *)NULL);
	numnum = printf("%p", "");
	character = ft_printf("%p", "");
	//character = printf("%i", numnum);
	printf("%i\n", numnum);
	//character = ft_printf("%i", numnum);
	ft_printf("%i\n", character);
	return (0);
}
*/