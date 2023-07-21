/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:16:56 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/21 11:16:26 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	i;
	char *dest;

	dest = NULL;
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	dest = malloc(i + 1);
	if (dest == NULL)
		return (0);
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strdup("Hello World"));
}
