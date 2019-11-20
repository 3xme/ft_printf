/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_dash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:49:51 by abiari            #+#    #+#             */
/*   Updated: 2019/11/20 01:49:53 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prints_dash(int *counter, char *s, int p, int *i)
{
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
	while (p-- > 0 && s[*i] != '\0')
	{
		ft_putchar(s[*i], counter);
		(*i)++;
	}
}

void	ft_prints_nodash(char *s, int *counter, int p, int *i)
{
	while (p-- > 0 && s[*i] != '\0')
	{
		ft_putchar(s[*i], counter);
		(*i)++;
	}
	while (g_spaces-- > 0)
		ft_putchar(' ', counter);
}
