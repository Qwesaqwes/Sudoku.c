/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 14:40:02 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/12 17:21:58 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// fonction pour remplacer les '.' par des '0'
void	*ft_change_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			str[i] = '0';
		i++;
	}
	return (str);
}

// fonction pour mettre le string sur le tableau int
char	*ft_add_str(char *str, int col)
{
	char	*tab;

	str = ft_change_str(str);
	tab = (char *)malloc(sizeof(*str) * 82);
	if (tab)
	{
		while (str[col] != '\0')
		{
			tab[col] = str[col];
			col++;
		}
	}
	return (tab);
}
