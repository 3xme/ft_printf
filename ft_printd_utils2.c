/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 04:34:49 by abiari            #+#    #+#             */
/*   Updated: 2019/11/20 04:35:14 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printud_both(int d, t_flags flags, int *counter)
{
	g_spaces = flags.width - flags.precision;
	g_o = flags.precision - ft_len(d);
	if (flags.dash == 0)
	{
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_putnbr(d, counter);
	}
	else
	{
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_putnbr(d, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}

void	ft_printsd_both(int d, t_flags flags, int *counter)
{
	d *= -1;
	g_spaces = flags.width - flags.precision - 1;
	g_o = flags.precision - ft_len(d);
	if (flags.dash == 0)
	{
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
		ft_putchar('-', counter);
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_putnbr(d, counter);
	}
	else
	{
		ft_putchar('-', counter);
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_putnbr(d, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}
