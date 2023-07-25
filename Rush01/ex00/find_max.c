/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:21:05 by hgandar           #+#    #+#             */
/*   Updated: 2023/07/23 11:24:13 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	write_col(int y, int x, int table_arr[6][6])
{
	int	i;
	int	number;

	i = 0;
	number = 1;
	while (i < 4)
	{
		table_arr[y + 1][x] = number;
		i++;
		y++;
		number++;
	}
	return (0);
}

int	write_row(int y, int x, int table_arr[6][6])
{
	int	i;
	int	number;

	i = 0;
	number = 1;
	while (i < 4)
	{
		table_arr[y][x + 1] = number;
		i++;
		x++;
		number++;
	}
	return (0);
}

void	find_max(int (*table_arr)[6], int row, int col, int y, int x)
{
	while (y < row)
	{
		x = 0;
		while (x < col)
		{
			if (y == 0 || y == 5)
			{	
				if (table_arr[y][x] == 4)
					write_col(y, x, table_arr);
				else if (table_arr[y][x] == 1)
					table_arr[y + 1][x] = 4;
			}
			else if (x == 0 || x == 5)
			{
				if (table_arr[y][x] == 4)
					write_row(y, x, table_arr);
				else if (table_arr[y][x] == 1)
					table_arr[y][x + 1] = 4;
			}
			x++;
		}
		y++;
	}
}	

int	main(void)
{	
	int	table_arr[6][6] = {{0, 4, 3, 2, 1, 0}, {4, 0, 0, 0, 0, 2}, {3, 0, 0, 0, 0, 2}, {2, 0, 0, 0, 0, 2}, {1, 0, 0, 0, 0, 2}, {0, 1, 2, 2, 2, 0}};
	const int	col;
	const int	row;
	const int	y;
	const int	x;

	col = 6;
	row = 6;
	y = 0;
	x = 0;
	find_max(table_arr, row, col, y, x);
}
