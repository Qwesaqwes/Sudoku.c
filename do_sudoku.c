/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 11:49:03 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/13 21:20:03 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_verif_lin(char **argv, int lin, char k)
{
	int col;

	col = 0;
	while (col < 9)
	{
		if (argv[lin][col] == k)
			return (0);
		col++;
	}
	return (1);
}

int		ft_verif_col(char **argv, int col, char k)
{
	int lin;

	lin = 0;
	while (lin < 9)
	{
		if (argv[lin][col] == k)
			return (0);
		lin++;
	}
	return (1);
}

int		ft_verif_bloc(char **argv, int lin, int col, char k)
{
	int lin2;
	int col2;

	lin2 = lin - (lin % 3);
	col2 = col - (col % 3);
	lin = lin2;
	while (lin < lin2 + 3)
	{
		col = col2;
		while (col < col2 + 3)
		{
			if (argv[lin][col] == k)
				return (1);
			col++;
		}
		lin++;
	}
	return (0);
}

int		ft_do_sudoku(char **argv, int lin, int col)
{
	char	nb;

	if (lin >= 9 || col >= 9)
		return (1);
	if (argv[lin][col] == '0')
	{
		nb = '1';
		while (nb <= '9')
		{
			if (ft_verif_lin(argv, lin, nb) == 1 &&
				ft_verif_col(argv, col, nb) == 1 &&
				ft_verif_bloc(argv, lin, col, nb) == 1)
			{
				argv[lin][col] = nb;
				if (ft_do_sudoku(argv, (col + 1) % 9, lin + ((col + 1) / 9)))
					return (1);
			}
			nb++;
		}
		argv[lin][col] = '0';
		return (0);
	}
	else
		return (ft_do_sudoku(argv, (col + 1) % 9, lin + ((col + 1) / 9)));
}
