/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:11:05 by akalican          #+#    #+#             */
/*   Updated: 2023/08/01 13:32:43 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include <stdio.h>

int		srch_dict(t_num *dict, int b_size, char *path);
int		size_dict(int *row, char *path);

void	convert_to_string(long num, t_num *dict);

long	ft_atoi(char *str)
{
	unsigned long	result;
	long			sign;
	int				q;

	result = 0;
	sign = 1;
	printf("Input: %s\n", str);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	q = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		if (++q > 18)
			return (-1);
		str++;
	}
	printf("Output: %ld\n", result);
//	if (*str != '\0')
//		return (-1);
	return (sign * result);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	free_dict(t_num *dict)
{
	int	i;

	i = 0;
	while (dict[i].num != -1)
	{
		free(dict[i].name);
		i++;
	}
	free(dict);
}

void	ft_snum(char *path, char *num)
{
	long	n;
	t_num	*dict;
	int		size;
	int		row;

	n = ft_atoi(num);
	if (n < 0)
	{
		write(1, "Error\n", 6);
		return ;
	}
	size = size_dict(&row, path);
	if (size < 0)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	dict = (t_num *)malloc((row + 1) * sizeof(t_num));
	if (srch_dict(dict, size, path) < 0)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	convert_to_string(n, dict);
	free_dict(dict);
}

int	main(int argc, char	**argv)
{	
	if (argc == 2)
	{
		ft_snum("numbers.dict", argv[1]);
	}
	else if (argc == 3)
	{
		ft_snum(argv[1], argv[2]);
	}
	return (0);
}
