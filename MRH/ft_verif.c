/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:53:49 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/22 15:38:51 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	we_see_x(int *x, int table[6][6], int start, int stop)
{
	int max;
	int dir;
	int	nb_found;
	
	dir = 1;
	if (stop < start)
		dir = -1;
	max = table[*x][start];
	printf("Direction: x %i\n", dir);
	printf("First: %d\n", table[*x][start]);
	nb_found = 1;
	while ((start + dir) != (stop + dir))
	{
		if ((max < table[*x][start + dir]))
		{
			nb_found++;
			max = table[*x][start + dir];
		}
		if (dir > 0)
			start++;
		else
			start--;
	}
	printf("We see %i towers\n*****************\n", nb_found);
	return (nb_found);
}

int	we_see_y(int *y, int table[6][6], int start, int stop)
{
	int max;
	int dir;
	int	nb_found;
	
	dir = 1;
	if (stop < start)
		dir = -1;
	max = table[start][*y];
	printf("Direction: y %i\n", dir);
	printf("First: %d\n", table[start][*y]);
	nb_found = 1;
	while ((start + dir) != (stop + dir))
	{
		if ((max < table[start + dir][*y]))
		{
			nb_found++;
			max = table[start + dir][*y];
		}
		if (dir > 0)
			start++;
		else
			start--;
	}
	printf("We see %i towers\n*****************\n", nb_found);
	return (nb_found);
}


int	verif_x(int table[6][6], int start, int stop)
{
	int x;

	if (start < stop)
	{
		x = 1;
		while (x <= stop)
		{
			printf("We want to see %i towers\n", table[x][0]);
			if (we_see_x(&x, table, start, stop) != table[x][0])
				return (x + (10 * start));
			x++;
		}
	}
	if (start > stop)
	{
		x = 1;
		while (x <= start)
		{
			printf("We want to see %i towers\n", table[x][start + 1]);
			if (we_see_x(&x, table, start, stop) != table[x][start + 1])
				return (x + (10 * start));
			x++;
		}
	}
	printf("###############\n");
	return (0);
}

int	verif_y(int table[6][6], int start, int stop)
{
	int y;

	if (start < stop)
	{
		y = 1;
		while (y <= stop)
		{
			printf("We want to see %i towers\n", table[0][y]);
			if (we_see_y(&y, table, start, stop) != table[0][y])
				return (y + (20 * start));
			y++;
		}
	}
	if (start > stop)
	{
		y = 1;
		while (y <= start)
		{
			printf("We want to see %i towers\n", table[start + 1][y]);
			if (we_see_y(&y, table, start, stop) != table[start + 1][y])
				return (y + (20 * start));
			y++;
		}
	}
	printf("###############\n");
	return (0);
}



int ft_verif(int t_size,int table[6][6])
{
	int	check;

	check = verif_x(table, 1, t_size);
	if (check != 0)
		return (check);
	check = verif_x(table, t_size, 1);
	if (check != 0)
		return (check);
	check = verif_y(table, 1, t_size);
	if (check != 0)
		return (check);
	check = verif_y(table, t_size, 1);
	if (check != 0)
		return (check);
	return (0);
}

int	main(void)
{
	int table[6][6] = { 
		{0, 1, 2, 4, 2, 0},
		{1, 4, 3, 1, 2, 3},
		{2, 3, 4, 2, 1, 3},
		{3, 2, 1, 3, 4, 1},
		{3, 1, 2, 4, 3, 2},
		{0, 4, 2, 2, 2, 0}
	};
	
	printf("Check: %d\n", ft_verif(4, table));
}
	
