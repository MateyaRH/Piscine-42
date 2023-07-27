/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:02:02 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/27 13:41:29 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	length(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != 0)
		{
			j++;
			count++;
		}
		j = 0;
		while (sep[j] != 0 && (i < size -1))
		{
			j++;
			count++;
		}
		i++;
	}
	return (count);
}

void	join_strs(char **strs, char **ret_str, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != 0)
		{
			(*ret_str)[k] = strs[i][j];
			j++;
			k++;
		}
		j = 0;
		while (sep[j] != 0 && (i < size - 1))
		{
			(*ret_str)[k] = sep[j];
			j++;
			k++;
		}
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret_str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	len = length(size, strs, sep);
	ret_str = (char *)malloc((len + 1) * sizeof(char));
	if (ret_str == NULL)
		return (0);
	join_strs(strs, &ret_str, sep, size);
	ret_str[len] = '\0';
	return (ret_str);
}
/*
int main(void)
{
	char *strs[4] = {"Hello", "world", "this is", "Ecole 42"};
	char *s = "++";

	char *r_s = ft_strjoin(4, strs, s);

	printf("String:\n%s\n", r_s);
}
*/
