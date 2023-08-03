/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:09:08 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/26 14:02:27 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sqroot(int nb, int i)
{
	if (nb >= i && ((i + 1) / 2) <= 46340)
	{
		return (1 + sqroot((nb - i), (i + 2)));
	}
	return (0);
}

int	ft_sqrt(int nb)
{
	int	x;

	x = 1;
	if (nb <= 0)
		return (0);
	x = sqroot(nb, x);
	if ((nb - (x * x) == 0))
		return (x);
	else
		return (0);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_sqrt(2147395600));
}

