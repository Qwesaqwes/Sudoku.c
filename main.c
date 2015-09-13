/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 11:07:31 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/13 17:16:26 by tgomiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_error(char **argv);
void	ft_print(int tab[9][9]);
void	ft_do_sudoku(int tab[9][9], int pos);

void	ft_save_sudoku(char **argv, int tab[9][9])
{
	int		lin;
	int		col;

	lin = 0;
	while (lin <= 8)
	{
		col = 0;
		while (col < 9)
		{
			tab[lin][col] = argv[lin + 1][col] - '0';
			col++;
		}
		lin++;
	}
}

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
	int		tab[9][9];

	if (argc == 10)
	{
		if (ft_check_error(argv) == 1)
		{
			write (1, "Erreur\n", 7);
			return (0);
		}
		ft_point_to_zero(argv);
		ft_save_sudoku(argv, tab);
		ft_do_sudoku(tab, 0);
		ft_print(tab);
	}
	else
		write (1, "Erreur\n", 7);
	return (0);
}
