/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgavilan <jgavilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:46:54 by jgavilan          #+#    #+#             */
/*   Updated: 2023/07/26 22:58:40 by jgavilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(char const *format, ...);
void	ft_unsigned_num(unsigned int num, int *count);
void	ft_hex_num(unsigned int num, int *count, char str);
void	ft_point_char(unsigned long point_char, int *count);
void	ft_putchar(int s, int *count);
void	ft_printwords(char *str, int *count);
void	ft_numbers(int num, int *count);
void	sel_func(char str, va_list args, int *count);
void	ft_head_point(unsigned long point_char, int *count);

#endif