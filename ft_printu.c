/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:50:12 by abiari            #+#    #+#             */
/*   Updated: 2019/11/20 04:26:00 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printuz_precz(t_flags flags, int *counter)
{
	g_spaces = flags.width;
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
}

void	ft_printu_prec(t_flags flags, int *counter, unsigned int d)
{
	g_spaces = flags.precision - ft_lenu(d);
	while (g_spaces-- > 0)
		ft_putchar('0', counter);
	ft_put_unbr(d, counter);
}

void	ft_printu(t_flags flags, va_list *args, int *counter)
{
	unsigned int	d;

	d = va_arg(*args, unsigned int);
	if (flags.is_flags == 0 || (flags.width <= ft_lenu(d) \
	&& flags.precision <= ft_lenu(d)))
	{
		if (d == 0 && flags.precision == 0)
			ft_printuz_precz(flags, counter);
		else
			ft_put_unbr(d, counter);
		return ;
	}
	if (flags.width >= ft_lenu(d) && flags.precision > ft_lenu(d))
		ft_printu_both(d, flags, counter);
	if (flags.width >= ft_lenu(d) && flags.precision <= ft_lenu(d))
	{
		if (d == 0 && flags.precision == 0)
			ft_printuz_precz(flags, counter);
		else
			ft_printu_width(d, flags, counter);
	}
	if (flags.width < ft_lenu(d) && flags.precision > ft_lenu(d))
		ft_printu_prec(flags, counter, d);
}
