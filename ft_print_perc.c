/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:48:53 by abiari            #+#    #+#             */
/*   Updated: 2019/11/20 01:48:58 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_perc(t_flags flags, int *counter)
{
	int spaces;

	spaces = flags.width - 1;
	if (flags.dash == 0)
	{
		if (flags.zero == 1)
		{
			while (spaces-- > 0)
				ft_putchar('0', counter);
		}
		else
		{
			while (spaces-- > 0)
				ft_putchar(' ', counter);
		}
		ft_putchar('%', counter);
	}
	else
	{
		ft_putchar('%', counter);
		while (spaces-- > 0)
			ft_putchar(' ', counter);
	}
}
