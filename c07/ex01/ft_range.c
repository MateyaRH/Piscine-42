/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:36:09 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/26 16:19:41 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	if (min >= max)
		return (NULL);
	i = max - min;
	range = (int *)malloc(i * sizeof(int));
	if (range == NULL)
		return (0);
	i--;
	while (i >= 0)
	{
		range[i] = max - 1;
		max--;
		i--;
	}
	return (range);
}
/*
#include <stdio.h>

int main(void)
{
	int i = 0;
	int *range = ft_range(-2, 4);
	while (i < 6)
	{
		printf("%d\n", range[i]);
		i++;
	}
}
*/
