/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:05:44 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/23 18:25:40 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void ft_2_3(int (*table)[6], int t_size)
{
	int	**table_t;
	int	i;
	int x;
	int	y;
	int nb3;
	int	nb6;

	nb3	= 0;
	nb6 = 0;

	i = 0;
	x = 0;
	table_t = (int **)malloc((t_size + 2) * sizeof(int*));
	while (i <= (t_size + 1))
	{
		table_t[i] = (int *)malloc((t_size + 2) * 4);
		i++;
	}
	while (x < (t_size + 2))
    {
		y = 0;
		while (y < (t_size + 2))
		{
			table_t[x][y] = 0;
			y++;
		}
		x++;
	}
	x = 1;
	while (x < t_size + 1)
	{
		y = 0;
		if (table[x][y] == 2)
		{
			if (table[x][y + 1] == 0)
				table_t[x][y + 1] = 6;
			else if (table[x][y + 1] == 3) 
				table_t[x][y + 1] = 3;
		}
		x++;
	}
	x = 1;
	while (x < t_size + 1)
	{
		y = t_size + 1;
		if (table[x][y] == 2)
		{
			if (table[x][y - 1] == 0)
				table_t[x][y - 1] = 6;
			else if (table[x][y - 1] == 3)
				table_t[x][y - 1] = 3;
		}
		x++;
	}
	y = 1;
	while (y < t_size + 1)
	{
		x = 0;
		if (table[x][y] == 2)
		{
			if (table[x + 1][y] == 0)
				table_t[x + 1][y] = 6;
			else if (table[x + 1][y] == 3) 
				table_t[x + 1][y] = 3;
		}
		else if (table[x][y] == 3)
		{
			if (table_t[x + 1][y] == 6)
				table_t[x + 1][y] = 0;
		}
		y++;
	}
	y = 1;
	while (y < t_size + 1)
	{
		x = t_size + 1;
		if (table[x][y] == 2)
		{
			if (table[x - 1][y] == 0)
				table_t[x - 1][y] = 6;
			else if (table[x - 1][y] == 3)
				table_t[x - 1][y] = 3;
		}
		else if (table[x][y] == 3)
		{
			if (table_t[x - 1][y] == 6)
				table_t[x - 1][y] = 0;
		}
		y++;
	}
	x = 1;
	y = 1;
	while (x <= t_size)
	{
		if (table_t[x][y] == 3)
			nb3++;
		if (table_t[x][y] == 6)
			nb6++;
		x++;
	}
	x = 1;
	if (nb3 == 0 && nb6 == 1)
	{
		while (x <= t_size)
		{
			if (table_t[x][y] == 6)
				table[x][y] = 3;
			x++;
		}
	}
	nb3 = 0;
	nb6 = 0;
	x = 1;
	y = 1;
	while (y <= t_size)
	{
		if (table_t[x][y] == 3)
			nb3++;
		if (table_t[x][y] == 6)
			nb6++;
		y++;
	}
	y = 1;
	if (nb3 == 0 && nb6 == 1)
	{
		while (y <= t_size)
		{
			if (table_t[x][y] == 6)
				table[x][y] = 3;
			y++;
		}
	}
	nb3 = 0;
	nb6 = 0;
	x = 1;
	y = t_size;
	while (x <= t_size)
	{
		if (table_t[x][y] == 3)
			nb3++;
		if (table_t[x][y] == 6)
			nb6++;
		x++;
	}
	x = 1;
	if (nb3 == 0 && nb6 == 1)
	{
		while (x <= t_size)
		{
			if (table_t[x][y] == 6)
				table[x][y] = 3;
			x++;
		}
	}
	nb3 = 0;
	nb6 = 0;
	x = t_size;
	y = 1;
	while (y <= t_size)
	{
		if (table_t[x][y] == 3)
			nb3++;
		if (table_t[x][y] == 6)
			nb6++;
		y++;
	}
	y = 1;
	if (nb3 == 0 && nb6 == 1)
	{
		while (y <= t_size)
		{
			if (table_t[x][y] == 6)
				table[x][y] = 3;
			y++;
		}
	}
	free(table_t);
}

int	main(void)
{
	int table[6][6] = {
		{0, 1, 2, 4, 2, 0},
		{1, 4, 0, 1, 0, 3},
		{2, 0, 0, 2, 0, 3},
		{3, 0, 0, 3, 4, 1},
		{3, 0, 0, 4, 0, 2},
		{0, 4, 2, 2, 2, 0}
	};
	
	ft_2_3(table, 4);
	printf("%d\n", table[4][4]);
}
