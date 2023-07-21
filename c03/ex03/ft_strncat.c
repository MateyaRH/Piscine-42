/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:54:10 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/19 13:08:31 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != 0)
		i++;
	while (src[j] != 0 && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s[20] = "World!";
	char d[20] = "Hello ";
    char d0[20] = "Hello ";
	unsigned int n = 5;

	printf("%s\n", strncat(d0, s, n));
	printf("%s\n", ft_strncat(d, s, n));
}
*/
