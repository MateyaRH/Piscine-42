/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftr_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 08:42:55 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/21 10:13:33 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ecrire_recurs(int nb)
{
	int		digit;
	char	c;

	digit = 0;
	if (nb != 0)
	{
		digit = nb % 10;
		c = digit + '0';
		ecrire_recurs(nb / 10);
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ecrire_recurs(nb);
}

int	main(void)
{
	ft_putnbr(4582);
}
