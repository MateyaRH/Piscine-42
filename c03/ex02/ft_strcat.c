/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:07:10 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/19 12:58:21 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != 0)
		i++;
	while (src[j] != 0)
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
	char s[20] = "brave new World!";
	char d[15] = "Hello ";
	char d0[15] = "Hello ";

//	printf("%s\n", strcat(d0, s));
	printf("%s\n", ft_strcat(d, s));
}
*/
