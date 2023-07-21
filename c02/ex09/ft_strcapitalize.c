/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mremenar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:14:40 by mremenar          #+#    #+#             */
/*   Updated: 2023/07/18 14:16:01 by mremenar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_alphanumeric(char *str, int i)
{
	if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
		|| (str[i] >= '0' && str[i] <= '9'))
	{
		return (0);
	}
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_alphanumeric(str, i) == 0)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			i++;
			while (ft_alphanumeric(str, i) == 0)
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] += 32;
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return (str);
}
/*
int	main(void)
{
	char s[] = "cOmment tu VAS ? 42mots quar4nte-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(s));
}
*/
