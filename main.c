/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 11:07:31 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/13 21:07:51 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_error(char **argv);
void	ft_print(char **argv);
int		ft_do_sudoku(char **argv, int lin, int col);

void	ft_point_to_zero(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.')
				argv[i][j] = '0';
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 10)
	{
		if (ft_check_error(argv) == 1)
		{
			write (1, "Erreur\n", 7);
			return (0);
		}
		ft_point_to_zero(argv);
		if (ft_do_sudoku(argv + 1, 0, 0))
			ft_print(argv);
	}
	else
		write (1, "Erreur\n", 7);
	return (0);
}
