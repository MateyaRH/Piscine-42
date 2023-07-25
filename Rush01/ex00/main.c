/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 07:55:48 by cmegret           #+#    #+#             */
/*   Updated: 2023/07/23 15:12:19 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	table_creation(int size, char *str, int **tab2d);

int	check_digit_limits(char *str, int count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] - '0') > (count / 4))
			return (-1);
		i++;
	}
	return (1);
}

int	count_digits(char *str)
{
	int	count;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' '))
			return (-1);
		i++;
	}
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			count++;
		i++;
	}
	return (count);
}

int	table_size(char *str)
{
	int	count;

	count = count_digits(str);
	if (count == -1)
		return (-1);
	if (check_digit_limits(str, count) == -1)
		return (-1);
	else if (count % 4 == 0)
		return (count / 4);
	else
		return (-1);
}

int	main(int argc, char **argv)
{
	int	size;
	int	**tab2d;

	tab2d = NULL;
	if (argc == 2)
	{
		size = table_size(argv[1]);
		if (size != -1)
		{
			table_creation(size + 2, argv[1], tab2d);
			return (0);
		}
		else
		{
			write(1, "Error\n", 5);
			return (-1);
		}
	}
	else
		write(1, "Error\n", 5);
	return (-1);
}
