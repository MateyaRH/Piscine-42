/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:34:41 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/13 15:02:40 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	x;
	int	y;
	int	d;
	int	m;
	int	*ptr_d;
	int	*ptr_m;

	x = 22;
	y = 5;
	ptr_d = &d;
	ptr_m = &m;
	ft_div_mod(x, y, ptr_d, ptr_m);
	printf("%i%i\n", d, m);
}
*/
