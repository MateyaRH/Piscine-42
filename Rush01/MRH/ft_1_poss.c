/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1_poss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:47:05 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/23 19:11:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int find_0(int t_size, int **table_0)
{
	int	x;
	int	y;

	printf("find_0\n");
	x = 1;
	while (x <= t_size)
	{
		y = 1;
		while (y <= t_size)
		{
			if (table_0[x][y] == 0)
				return((x * 10) + y);
			y++;
		}
		x++;
	}
	return (0);
}


int fill_t(int t_size, int **t_t, int par_x, int par_y)
{
	int			x;
	int			y;
	int			i;

	printf("fill_t, par_x: %d, par_y: %d\n", par_x, par_y);
	x = par_x % 10;
	par_x /= 10;
	y = par_y % 10;
	par_y /= 10;
	while (x >= 1 && y >= 1)
	{
		i = 1;
		while (i < t_size)
		{
			t_t[i][y] = 7;
			t_t[x][i] = 7;
			i++;
		}
		x = par_x % 10;
		par_x /= 10;
		y = par_y % 10;
		par_y /= 10;
	}
	printf("Avant apelle find_0, table : %d\n", t_t[2][2]);	
	return (find_0(t_size, t_t));
}


int find_xy(int t_size, int param_x, int param_y)
{
	int	**table_t;
	int	i;
	int	p_xy;

	printf("find_xy\n");
	i = 0;
	table_t = (int **)malloc((t_size + 2) * sizeof(int*));
	while (i < (t_size + 2))
	{
		table_t[i] = (int *)malloc((t_size + 2) * 4);
		i++;
	}
	p_xy = fill_t(t_size, table_t, param_x, param_y);
	free (table_t);
	return (p_xy);
}

void ft_1_poss(int t_size, int (*table)[6], int cible)
{
	int	p_x;
	int	p_y;
	int	x;
	int	y;
	int p_xy;

	x = 1;
	p_x = 0;
	p_y = 0;
	while (x < (t_size + 1))
	{
		y = 1;
		while(y < (t_size + 1))
		{
			if (table[x][y] == cible)
			{
				p_x *= 10;
				p_x += x;
				p_y *= 10;
				p_y += y;
			}
			y++;
		}
		x++;
	}
	printf("p_x: %d\np_y: %d\n", p_x, p_y);
	p_xy = find_xy(t_size, p_x, p_y);
	printf("p_xy: %d\n", p_xy);
	y = p_xy % 10;
	x = (p_xy / 10) % 10;
	table[x][y] = cible;
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
	ft_1_poss(4, table, 4);
	printf("Table: %d\n", table[2][2]);
}
