/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 11:49:03 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/13 17:15:00 by tgomiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void  ft_print(int tab[9][9]);

int		ft_verif_lin(int tab[9][9], int lin, int k)
{
	int col;

	col = 0;
	while (col < 9)
	{
		if (tab[lin][col] == k)
			return (1);
		col++;
	}
	return (0);
}

int		ft_verif_col(int tab[9][9], int col, int k)
{
	int lin;

	lin = 0;
	while (lin < 9)
	{
		if (tab[lin][col] == k)
			return (1);
		lin++;
	}
	return (0);
}

int		ft_verif_bloc(int tab[9][9], int lin, int col, int k)
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
			if (tab[lin][col] == k)
				return (1);
			col++;
		}
		lin++;
	}
	return (0);
}

int		ft_do_sudoku(int tab[9][9], int pos)
{
	int		lin;
	int		col;
	int		nb;

	lin = pos / 9;
	col = pos % 9;
	nb = 1;
	if (pos == 81)
		return (0);
	if (tab[lin][col] != 0)
		return (ft_do_sudoku(tab, pos + 1));
	while (nb <= 9)
	{
		if (ft_verif_lin(tab, lin, nb) == 1 &&
			ft_verif_col(tab, col, nb) == 1 &&
			ft_verif_bloc(tab, lin, col, nb) == 1)
			tab[lin][col] = nb;
		if (pos + 1 <= 81)
			return (ft_do_sudoku(tab, pos + 1));
		nb++;
	}
	tab[lin][col] = 0;
	return (1);
}
