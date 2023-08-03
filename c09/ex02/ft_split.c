/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:21:32 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/31 10:17:47 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char s, char *cset)
{
	int	i;

	i = 0;
	while (cset[i] != 0)
	{
		if (s == cset[i])
			return (1);
		i++;
	}
	return (0);
}

int	size_str(char *str, char *cset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (check_sep (str[i], cset) == 0 && str[i] != 0)
	{
		count++;
		i++;
	}
	return (count);
}

int	count_strs(char *str, char *cset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		while (check_sep(str[i], cset) == 1 && str[i] != 0)
			i++;
		if (str[i] != 0)
			count++;
		while (check_sep(str[i], cset) == 0 && str[i] != 0)
			i++;
	}
	return (count);
}

char	*cpy_str(char *str, char *cset)
{
	int		i;
	int		len;
	char	*c_str;

	i = 0;
	len = 0;
	len = size_str(str, cset);
	c_str = (char *)malloc((len + 1) * sizeof(char));
	if (c_str == NULL)
		return (0);
	while (i < len)
	{
		c_str[i] = str[i];
		i++;
	}
	c_str[i] = '\0';
	return (c_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret_arr;
	int		i;
	int		no_arr;

	no_arr = count_strs(str, charset);
	ret_arr = (char **)malloc((no_arr + 1) * sizeof(char *));
	if (ret_arr == NULL)
		return (0);
	i = 0;
	while (i < no_arr)
	{
		while (check_sep(*str, charset) == 1 && *str != 0)
			str++;
		if (*str != 0)
		{
			ret_arr[i] = cpy_str(str, charset);
			i++;
		}
		while (check_sep(*str, charset) == 0 && *str != 0)
			str++;
	}
	ret_arr[i] = (char *)malloc(sizeof(char));
	ret_arr[i] = 0;
	return (ret_arr);
}
/*
#include <stdio.h>

int main(void)
{
	char *s = "Hello world this is ecole 42";
	char *cset = "Hh";
	char **result = ft_split(s, cset);
	int i = 0;

	while (result[i] != 0)
	{
		printf("%s\n", result[i]);
		i++;
	}
}
*/
