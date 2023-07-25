/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2to3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 07:30:28 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/23 13:06:32 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int find_match(int value)
{
	int	match;

	match = 0;
	if (value == 1)
		match = 2341;
	else if (value == 2)
		match = 1342;
	else if (value == 3)
		match = 1243;
	else
		match = -1;
	return (match);
}

void verify2_3_x(int (*table)[6], int t_size, int x, int dir)
{
	int	y;
	int	nb;
	int match;

	match = 0;
	nb = 0;
	if (dir > 0)
		y = 0;
	else
		y = t_size + 1;	
	if (table[x][y + (1 * dir)] != 0)
		 match = (find_match(table[x][y + (1 * dir)]));
	if (table[x][y + (3 * dir)] == 2)
		match = 1243;
	if (table[x][y + (4 * dir)] == 2)
		match = 2341;
	if (match != 0)
	{
		while (match >= 1)
		{
			nb = match % 10;
			match /= 10;
			table[x][y + (1 * dir)] = nb;
			y = y + (1 * dir);
		}
	}
}

void verify2_3_y(int (*table)[6], int t_size, int y, int dir)
{
	int	x;
	int	nb;
	int match;

	match = 0;
	nb = 0;
	if (dir > 0)
		x = 0;
	else
		x = t_size + 1;	
	if (table[x + (1 * dir)][y] != 0)
		 match = (find_match(table[x + (1 * dir)][y]));
	else if (table[x + (3 * dir)][y] == 2)
		match = 1243;
	else if (table[x + (4 * dir)][y] == 2)
		match = 2341;
	if (match != 0)
	{
		while (match >= 1)
		{
			nb = match % 10;
			match /= 10;
			table[x + (1 * dir)][y] = nb;
			x = x + (1 * dir);
		}
	}
}


void scan_x(int (*table)[6], int t_size)
{
	int	x;
	int	y;
	int	dir;

	x = 1;
	while (x <= (t_size))
	{
		y = 0;
		if (table[x][y] == 2)
		{
			dir = 1;
			if (table[x][y + (t_size + 1)] == 3)
			{
				while (table[x][y + 1] != 0 && y != (t_size + 1))
					y++;
				if (y != (t_size + 1))
					verify2_3_x(table, t_size, x, dir);
			}
		}
		else if (table[x][y] == 3)
		{
			dir = -1;
			if(table[x][y + (t_size + 1)] == 2)
			{
				while (table[x][y + 1] != 0 && y != (t_size + 1))
					y++;
				if (y != (t_size + 1))
					verify2_3_x(table, t_size, x, dir);
			}
		}
		x++;
	}
}

void scan_y(int (*table)[6], int t_size)
{
	int	x;
	int	y;
	int	dir;

	y = 1;
	while (y <= (t_size))
	{
		x = 0;
		if (table[x][y] == 2)
		{
			dir = 1;
			if (table[x + (t_size + 1)][y] == 3)
			{
				while (table[x + 1][y] != 0 && x != (t_size + 1))
					x++;
				if (x != (t_size + 1))
					verify2_3_y(table, t_size, y, dir);
			}
		}
		else if (table[x][y] == 3)
		{
			dir = -1;
			if(table[x + (t_size + 1)][y] == 2)
			{
				while (table[x + 1][y] != 0 && x != (t_size + 1))
					x++;
				if (x != (t_size + 1))
					verify2_3_y(table, t_size, y, dir);
			}
		}
		y++;
	}
}


void ft_2to3(int (*table)[6], int t_size)
{
	scan_x(table, t_size);
	scan_y(table, t_size);
}

int	main(void)
{
	int table[6][6] = {
		{0, 1, 2, 4, 2, 0},
		{1, 4, 3, 1, 2, 3},
		{2, 0, 0, 0, 0, 3},
		{3, 2, 1, 3, 4, 1},
		{3, 0, 0, 0, 0, 2},
		{0, 4, 3, 2, 2, 0}
	};

	ft_2_3(table, 4);
	printf("Check: %d\n", table[4][2]);

	return (0);
}
