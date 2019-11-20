/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:49:08 by abiari            #+#    #+#             */
/*   Updated: 2019/11/20 04:25:25 by abiari           ###   ########.fr       */
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

void	ft_printsd_width(int d, t_flags flags, int *counter)
{
	if (d >= 0)
	{
		g_spaces = flags.width - ft_len(d);
		if (flags.dash == 0)
		{
			while (g_spaces-- > 0)
			{
				if (flags.zero == 1 && flags.precision <= ft_len(d)\
				&& flags.precision >= 0)
					ft_putchar(' ', counter);
				else if (flags.zero == 1)
					ft_putchar('0', counter);
				else
					ft_putchar(' ', counter);
			}
			ft_putnbr(d, counter);
		}
		else
		{
			ft_putnbr(d, counter);
			while (g_spaces-- > 0)
				ft_putchar(' ', counter);
		}
	}
}

void	ft_printud_prec(int *counter, int d)
{
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
	ft_putchar('-', counter);
	ft_putnbr(d * -1, counter);
}

void	ft_printud_zero(int *counter, int d)
{
	ft_putchar('-', counter);
	while (g_spaces-- > 0)
		ft_putchar('0', counter);
	ft_putnbr(d * -1, counter);
}

void	ft_printud_width(int d, t_flags flags, int *counter)
{
	g_spaces = flags.width - ft_len(d * -1) - 1;
	if (flags.dash == 0)
	{
		if (flags.zero == 1 && flags.precision <= ft_len(d)\
		&& flags.precision >= 0)
			ft_printud_prec(counter, d);
		else if (flags.zero == 1)
			ft_printud_zero(counter, d);
		else
		{
			while (g_spaces-- > 0)
				ft_putchar(' ', counter);
			ft_putnbr(d, counter);
		}
	}
	else if (flags.dash == 1)
	{
		ft_putnbr(d, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
}
