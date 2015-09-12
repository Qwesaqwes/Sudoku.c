/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 11:07:31 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/12 17:32:11 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_add_str(char *str, int col);

int		main(int argc, char **argv)
{
	int		i;
	int		col;
	char	*str;
	char	tab[9][9];

	i = 1;
	col = 0;
	if (argc == 10)
	{
		while (i < argc)
		{
			str = argv[i];
//		if (ft_check_error(str) == 1)
//			write(1, "E\n", 2);
			tab = ft_add_str(str, col);
			printf ("%s", tab);
			i++;
		}
	}
	else
		write(1, "E\n", 2);
}