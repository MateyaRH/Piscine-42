/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:24:01 by cmegret           #+#    #+#             */
/*   Updated: 2023/07/23 15:09:01 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/* #include <stdio.h>

void	print_table(int size, int **tab)
{
	int	l;
	int	c;

	l = 0;
	while (l < size)
	{
		c = 0;
		while (c < size)
		{
			printf("%d ", tab[l][c]);
			c++;
		}
		printf("\n");
		l++;
	}
} */

void	initialize_tab_param(char *str, char *tab_param)
{
	int	n;

	n = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			tab_param[n] = *str;
			n++;
		}
		str++;
	}
}

void	initialize_tab2d(int size, int **tab)
{
	int	l;
	int	c;

	l = 0;
	while (l < size)
	{
		c = 0;
		while (c < size)
		{
			tab[l][c] = 0;
			c++;
		}
		l++;
	}
}

void	fill_row(int size, int **tab2d, char *tab_param, int *n)
{
	int	c;
	int	l;

	c = 1;
	if (*n == 0)
		l = 0;
	if (*n == (size - 2))
		l = size - 1;
	while (c > 0 && c < size - 1)
	{
		tab2d[l][c] = tab_param[*n] - '0';
		(*n)++;
		c++;
	}
}

void	fill_column(int size, int **tab2d, char *tab_param, int *n)
{
	int	c;
	int	l;

	l = 1;
	if (*n == (size + 2))
		c = 0;
	if (*n == (size * 2))
		c = size - 1;
	while (l > 0 && l < size - 1)
	{
		tab2d[l][c] = tab_param[*n] - '0';
		(*n)++;
		l++;
	}
}

void	table_creation(int size, char *str, int **tab2d)
{
	char	*tab_param;
	int		i;
	int		n;

	tab2d = (int **)malloc(size * sizeof(int *));
	i = 0;
	while (i < size)
	{
		tab2d[i] = (int *)malloc(size * sizeof(int));
		i++;
	}
	tab_param = malloc((size * size) * sizeof(char));
	initialize_tab_param(str, tab_param);
	initialize_tab2d(size, tab2d);
	n = 0;
	fill_row(size, tab2d, tab_param, &n);
	fill_row(size, tab2d, tab_param, &n);
	fill_column(size, tab2d, tab_param, &n);
	fill_column(size, tab2d, tab_param, &n);
}
