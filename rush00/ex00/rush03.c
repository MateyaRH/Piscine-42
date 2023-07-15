/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:04:07 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/15 11:30:37 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y)
{
	int	i;
	int	j;

//	ft_putchar("A");
	write(1, "A", 1);
	i = 1;
	j = 2;
	while (i <= y)
	{
		while (j < x)
		{
			if (i == 1 || i == y)
			{
				while (j != x)
				{
					//					ft_putchar("B");
					write(1, "B", 1);
					j++;
				}
				//				ft_putchar("C");
				write(1, "C", 2);
			}
			else
			{
				while (j != x)
				{
					//					ft_putchar(" ");
					write(1, " ", 1);
					j++;
				}
//				ft_putchar("B");
				write(1, "B", 2);
			}
		}
		j = 2;
//		ft_putchar("\n");
		write(1, "\n", 1);
		i++;
		if (i < y)
		{
//			ft_putchar("B");
			write(1, "B", 1);
		}
		else
		{
			if (i == y)
			{
//				ft_putchar("A");
				write(1, "A", 1);
			}
		}
	}
}

int	main(void)
{
	rush(123, 42);
	return (0);
}
