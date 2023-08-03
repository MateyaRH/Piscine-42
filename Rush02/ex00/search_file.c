/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:27:04 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/30 20:27:16 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

int	size_line(char *buff, int i, int b_size)
{
	int	j;

	j = 0;
	while (buff[i] != '\n' && i < b_size)
	{
		i++;
		j++;
	}
	return (j);
}

long	find_num(char *buff, char *num_c, int i, int b_size)
{
	int		j;
	long	num_l;

	j = 0;
	num_l = 0;
	while (buff[i] != '\n' && i < b_size)
	{
		num_c[j] = buff[i];
		j++;
		i++;
	}
	num_c[j] = '\0';
	num_l = atoi(num_c);
	return (num_l);
}

char	*find_value(char *buff, int b_size, long *num_l, int *i)
{
	int		p;
	int		j;
	char	*num_c;

	p = *i;
	num_c = malloc((size_line(buff, p, b_size) + 1) * sizeof(char));
	*num_l = find_num(buff, num_c, p, b_size);
	j = 0;
	while (buff[p] != ':' && p < b_size)
		p++;
	if (p < b_size)
		p++;
	while (buff[p] == ' ' && p < b_size)
		p++;
	while (buff[p] != '\n' && p < b_size)
	{
		num_c[j] = buff[p];
		j++;
		p++;
	}
	while (num_c[j - 1] == ' ')
		j--;
	num_c[j] = '\0';
	*i = p + 1;
	return (num_c);
}

int	handle_file(char **buff, int b_size, int off, char *path)
{
	int	file;

	file = 0;
	if (off == 1)
	{
		free (*buff);
		close (file);
		return (0);
	}
	file = open(path, O_RDONLY);
	if (file < 0)
		return (-1);
	*buff = (char *)malloc((b_size + 1) * sizeof(char));
	if (*buff == NULL)
	{
		close (file);
		return (-1);
	}
	read(file, *buff, b_size);
	return (0);
}

int	srch_dict(t_num *dict, int b_size, char *path)
{
	char	*num_c;
	long	num_l;
	char	*buff;
	int		i;
	int		row;

	row = 0;
	i = 0;
	if (handle_file(&buff, b_size, 0, path) == 0)
	{
		while (i < b_size)
		{
			num_c = find_value(buff, b_size, &num_l, &i);
			if (num_l >= 0)
			{
				dict[row].num = num_l;
				dict[row++].name = num_c;
			}
		}
		dict[row].num = -1;
		handle_file(&buff, b_size, 1, path);
		return (0);
	}
	return (-1);
}
