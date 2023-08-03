/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:55:31 by mremenar          #+#    #+#             */
/*   Updated: 2023/08/02 15:18:24 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

int	cpy_to_strct(t_stock_str *ar, char **av, int i)
{
	int	j;

	j = 0;
	if (ar[i].copy == NULL)
	{
		while (j < i)
		{
			free(ar[j].copy);
			j++;
		}
		free(ar);
		return (0);
	}
	while (av[i][j])
	{
		ar[i].copy[j] = av[i][j];
		j++;
	}
	ar[i].copy[j] = 0;
	return (1);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str	*ar;

	ar = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (ar == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		ar[i].size = j;
		ar[i].str = av[i];
		ar[i].copy = (char *)malloc((j + 1) * sizeof(char));
		if (!cpy_to_strct(ar, av, i))
			return (NULL);
		i++;
	}	
	ar[i].str = 0;
	return (ar);
}
/*
int main(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	char *av[3] =
	{
		"Hello",
		"world",
		"!"
	};

	t_stock_str *ar = ft_strs_to_tab(3, av);
	ft_show_tab(ar);

	while (ar[i].str != 0)
	{
		printf("Size: %d\n", ar[i].size);
		printf("Str: %s\n", ar[i].str);
		printf("Copy: %s\n", ar[i].copy);
		printf("#######");
		i++;
	}
}
*/
