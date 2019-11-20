/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:49:01 by abiari            #+#    #+#             */
/*   Updated: 2019/11/20 01:49:04 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printc(t_flags flags, va_list *args, int *counter)
{
	char	c;
	int		spaces;

	spaces = flags.width - 1;
	c = va_arg(*args, int);
	if (flags.dash == 0)
	{
		while (spaces-- > 0)
			ft_putchar(' ', counter);
		ft_putchar(c, counter);
	}
	else
	{
		ft_putchar(c, counter);
		while (spaces-- > 0)
			ft_putchar(' ', counter);
	}
}
