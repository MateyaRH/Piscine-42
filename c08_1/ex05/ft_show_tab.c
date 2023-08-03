/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:08:11 by mremenar          #+#    #+#             */
/*   Updated: 2023/08/02 13:50:13 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	prt_int(int size)
{
	int		i;
	char	nb[11];

	i = 10;
	nb[10] = 0;
	while (size > 0)
	{
		i--;
		nb[i] = (size % 10) + '0';
		size /= 10;
	}
	while (nb[i] != 0)
	{
		write(1, &nb[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	prt_str(char *str, int t)
{
	write(1, str, t);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		prt_str(par[i].str, par[i].size);
		prt_int(par[i].size);
		prt_str(par[i].copy, par[i].size);
		i++;
	}
}
