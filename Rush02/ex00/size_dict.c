/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:58:13 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/30 18:46:03 by dmiasnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	size_dict(int *row, char *path)
{
	int		dict_size;
	int		file;
	char	b;

	dict_size = 0;
	*row = 1;
	file = open(path, O_RDONLY);
	if (file < 0)
		return (-1);
	while (read(file, &b, 1) > 0)
	{
		if (b == '\n')
			*row = *row + 1;
		dict_size++;
	}
	close (file);
	return (dict_size);
}
