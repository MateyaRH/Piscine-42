/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:42:43 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/18 09:44:39 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{	
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}	
	return (1);
}
/*
int	main(void)
{
	char *s = "2656 6265";
    printf("%d\n", ft_str_is_numeric(s));
}
*/
