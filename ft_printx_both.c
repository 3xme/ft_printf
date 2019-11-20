/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:50:19 by abiari            #+#    #+#             */
/*   Updated: 2019/11/20 01:50:22 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printx_both(unsigned int d, t_flags flags, int *counter, int flag)
{
	char	*tmp;

	if ((tmp = convert(d, 16, flag)) == NULL)
		return (-1);
	g_spaces = flags.width - flags.precision;
	g_o = flags.precision - ft_lenx(d);
	if (flags.dash == 0)
	{
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_putstr(tmp, counter);
	}
	else
	{
		while (g_o-- > 0)
			ft_putchar('0', counter);
		ft_putstr(tmp, counter);
		while (g_spaces-- > 0)
			ft_putchar(' ', counter);
	}
	free(tmp);
	return (0);
}
