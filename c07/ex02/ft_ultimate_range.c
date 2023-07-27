/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:35:53 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/27 08:58:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{	
	int	i;

	i = max - min;
	*range = (int *)malloc(i * sizeof(int));
	if (range == NULL)
		return (-1);
	if (i <= 0)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int main(void)
{
	int *range;
	int i;

	i = 0;
	int size = ft_ultimate_range(&range, -2, 4);
	printf("size: %d\n", size);
	while (i < size)
	{
		printf("%d\n", range[i]);
		i++;
	}
}
*/
