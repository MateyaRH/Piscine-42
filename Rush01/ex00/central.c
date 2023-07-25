/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:59:13 by hgandar           #+#    #+#             */
/*   Updated: 2023/07/23 18:14:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	**create_mini(int row, int col, int size)
{
	int ** mini_table;
	int y;
	int x;
	
	y = 1;
	x = 0;
	mini_table = malloc(sizeof(int*)*row);
	mini_table[0][0] = 1;
	mini_table[0][1] = 2;
	mini_table[0][2] = 3;
	mini_table[0][3] = 4;
	while (y == 1)
	{
		while (x < col)
		{
			mini_table[y][x] = 0;
			x++;
		}
		y++;
	}
	return mini_table;
}

int	**mini_check(int (**table_arr)[6], int **mini_table)
{
	int y;
	int x;
	int value;

	x = 0;
	y = 0;
	value = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			if (table_arr[y][x] != 0)
			{
				value = table_arr[y][x];
				{
					while (mini_table[0][x])
					{
						if (x == value && x < 4)
							mini_table[1][x] += 1;
					}
				}
			}
			x++;
		}
		y++;
	}
	return mini_table;
} 

void    centrale(int (*table_arr)[6], int row, int col, int y, int x)
{
	int **mini_table = create_mini(2, 4, 0);

	//find_max(int (*table_arr)[6], int row, int col, int y, int x);
	mini_table = mini_check(table_arr, mini_table);
	y = 1;
	x = 0;
	while (y == 1)
	{
		while (x < 4)
		{
			if (mini_table[1][x] == 3)
				//ft_1_poss(int ((*table_arr)[6], int 4);
				//ft_2_3();
				//ft_last_poss();
				//ft_2_poss();
		}
		x++;
		if sucess
		{
			y = 0;
			x = 0;
			while (y < row)
			{
				while (x < col)
				{
					free(mini_table);
					x++;
				}
				y++;
			}
		}
	}
}

int main(void)
{
    int table_arr[6][6] = {{0, 4, 3, 2, 1, 0}, {4, 0, 0, 0, 0, 2}, {3, 0, 0, 0, 0, 2}, {2, 0, 0, 0, 0, 2}, {1, 0, 0, 0, 0, 2}, {0, 1, 2, 2, 2, 0}};
    int   col;
    int   row;
	int   y;
    int   x;

    col = 6;
    row = 6;
    y = 0;
    x = 0;
   // find_max(table_arr, row, col, y, x);
   centrale(table_arr, row, col, y, x);
}
