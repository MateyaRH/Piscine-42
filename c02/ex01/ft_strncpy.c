/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:52:02 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/19 12:11:59 by mremenar         ###   ########.fr       */
/*  																		  */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *source0 = "Ecole 42";
    char *source = "Ecole 42";
	char destin0[20] = "555555555555555555";
    char destin[20] = "555555555555555555";
	unsigned int n = 10;
	unsigned int i = 0;

	printf("%s\n", strncpy(destin0, source0, n));
	ft_strncpy(destin, source, n);

	while (i <= 15)
	{ 
		if (destin[i] == '\0')
			printf("\\0");
		else
			printf("%c", destin[i]);
		i++;
	}
		printf("\n");
	printf("%s\n", destin);
}
*/
