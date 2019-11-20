/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:49:34 by abiari            #+#    #+#             */
/*   Updated: 2019/11/20 01:58:14 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	g_flags;

void	flags_init(t_flags *flags)
{
	flags->dash = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->is_flags = 0;
}

int		ft_check_format(char c, int *count, va_list *args)
{
	if (c == 'd' || c == 'i')
		ft_printd(g_flags, args, count);
	if (c == 'u')
		ft_printu(g_flags, args, count);
	if (c == 'p')
		if (ft_printp(g_flags, args, count) == -1)
			return (-1);
	if (c == 'X')
		if (ft_printx(g_flags, args, count, 1) == -1)
			return (-1);
	if (c == 'x')
		if (ft_printx(g_flags, args, count, 0) == -1)
			return (-1);
	if (c == 's')
		ft_prints(g_flags, args, count);
	if (c == 'c')
		ft_printc(g_flags, args, count);
	if (c == '%')
		ft_print_perc(g_flags, count);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		flags_init(&g_flags);
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i], &count);
			i++;
		}
		if (format[i] != '\0')
			i++;
		ft_getflags((char *)format, &g_flags, &args, &i);
		if (ft_check_format((char)format[i], &count, &args))
			return (-1);
		if (format[i] != '\0')
			i++;
	}
	va_end(args);
	return (count);
}
