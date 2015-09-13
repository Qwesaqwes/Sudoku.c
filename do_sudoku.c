/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtserenb <gtserenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 14:44:25 by gtserenb          #+#    #+#             */
/*   Updated: 2015/09/13 21:43:57 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_verif_lin(char **tab, int y, char nb)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (tab[y][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int		ft_verif_col(char **tab, int x, char nb)
{
	int		j;

	j = 0;
	while (j < 9)
	{
		if (tab[j][x] == nb)
			return (0);
		j++;
	}
	return (1);
}

int		ft_verif_bloc(char **tab, int x, int y, char nb)
{
	int		i;
	int		j;

	i = (x / 3) * 3;
	while (i < (x / 3) * 3 + 3)
	{
		j = (y / 3) * 3;
		while (j < (y / 3) * 3 + 3)
		{
			if (tab[j][i] == nb)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_do_sudoku(char **tab, int x, int y)
{
	char	nb;

	if (y >= 9 || x >= 9)
		return (1);
	if (tab[y][x] == '0')
	{
		nb = '1';
		while (nb <= '9')
		{
			if (ft_verif_lin(tab, y, nb) && ft_verif_col(tab, x, nb)
				&& ft_verif_bloc(tab, x, y, nb))
			{
				tab[y][x] = nb;
				if (ft_do_sudoku(tab, (x + 1) % 9, y + ((x + 1) / 9)))
					return (1);
			}
			nb++;
		}
		tab[y][x] = '0';
		return (0);
	}
	else
		return (ft_do_sudoku(tab, (x + 1) % 9, y + ((x + 1) / 9)));
}
