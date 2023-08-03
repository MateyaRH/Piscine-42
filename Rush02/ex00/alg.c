/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:37:47 by dmiasnik          #+#    #+#             */
/*   Updated: 2023/07/30 18:50:46 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}	

char	*ft_concat(char *str1, char *str2)
{
	char	*str;
	int		i;
	int		j;

	if (str1 == 0 || str2 == 0)
	{
		if (str2 != 0)
			free(str2);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 2));
	i = 0;
	j = 0;
	while (str1[i])
		str[j++] = str1[i++];
	if (i > 0 && *str2)
		str[j++] = ' ';
	i = 0;
	while (str2[i])
		str[j++] = str2[i++];
	str[j] = '\0';
	free(str2);
	return (str);
}

char	*find_name(t_num *dict, long num)
{
	while (dict->num != -1)
	{
		if (dict->num == num)
		{
			return (dict->name);
		}
		dict++;
	}
	return (0);
}

char	*convert000(long num, t_num *dict, long d)
{
	long	h;
	char	*str;

	str = malloc(sizeof(char));
	*str = '\0';
	if (d > 1 && num % 1000 > 0)
		str = ft_concat(find_name(dict, d), str);
	h = num % 100;
	if (h >= 0 && h <= 19)
		str = ft_concat(find_name(dict, h), str);
	else if (h > 0 && h % 10 == 0)
		str = ft_concat(find_name(dict, h), str);
	else if (h > 0)
	{
		str = ft_concat(find_name(dict, h % 10), str);
		str = ft_concat(find_name(dict, h - h % 10), str);
	}
	num = num - h;
	h = num % 1000;
	if (h > 0)
	{
		str = ft_concat(find_name(dict, 100), str);
		str = ft_concat(find_name(dict, h / 100), str);
	}
	return (str);
}

char	*convert(long num, t_num *dict, long d)
{
	char	*str;
	char	*str2;

	str = convert000(num, dict, d);
	num /= 1000;
	if (num > 0)
	{
		str2 = convert(num, dict, d * 1000);
		str = ft_concat(str2, str);
		if (str2 != 0)
			free(str2);
	}
	return (str);
}

void	convert_to_string(long num, t_num *dict)
{
	char	*str;

	str = convert(num, dict, 1);
	if (str == 0)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}
