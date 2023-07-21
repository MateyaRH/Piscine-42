/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:09:04 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/13 15:33:13 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;

	div = *a / *b;
	*b = *a % *b;
	*a = div;
}
/*
int	main(void)
{
	int	x;
	int	y;

	x = 22;
	y = 5;
	ft_ultimate_div_mod(&x, &y);
	printf("%i%i\n", x, y);
}
*/
