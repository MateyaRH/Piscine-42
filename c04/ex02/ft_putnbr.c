/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:31:03 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/20 14:22:41 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_negatif(int number, int *negatif)
{
	number += 1;
	number *= -1;
	write(1, "-", 1);
	*negatif = 1;
	return (number);
}

void	ft_int_to_char(char *string, int number)
{
	int	i;
	int	digit;

	i = 10;
	string[i] = '\0';
	i--;
	while (i >= 0)
	{
		digit = 0;
		digit = number % 10;
		number /= 10;
		string[i] = digit + '0';
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	int		neg;
	char	c[11];

	neg = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
		nb = ft_is_negatif(nb, &neg);
	ft_int_to_char(c, nb);
	if (neg == 1)
		c[9]++;
	i = 0;
	while (c[i] == '0')
		i++;
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
}
/*
int	main(void)
{
	ft_putnbr(0);
	return (0);
}
*/
