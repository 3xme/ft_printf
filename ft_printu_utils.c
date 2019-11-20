/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 04:26:04 by abiari            #+#    #+#             */
/*   Updated: 2019/11/20 04:26:14 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printu_both(unsigned int d, t_flags flags, int *counter)
{
	g_spaces = flags.width - flags.precision;
	g_o = flags.precision - ft_lenu(d);
	if (flags.dash == 0)
	{
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_put_unbr(d, counter);
	}
	else
	{
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_put_unbr(d, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}

void	ft_printu_width(unsigned int d, t_flags flags, int *counter)
{
	g_spaces = flags.width - ft_lenu(d);
	if (flags.dash == 0)
	{
		while (g_spaces-- > 0)
		{
			if (flags.zero == 1 && flags.precision <= ft_lenu(d)\
			&& flags.precision >= 0)
				ft_putchar(' ', counter);
			else if (flags.zero == 1)
				ft_putchar('0', counter);
			else
				ft_putchar(' ', counter);
		}
		ft_put_unbr(d, counter);
	}
	else
	{
		ft_put_unbr(d, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}
