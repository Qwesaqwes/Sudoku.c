/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 11:49:03 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/13 13:26:55 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_verif_column(char **argv, int col)
{
	int		line;

	line = 1;
	while (line <= 9)
	{
		argv[in][col] == 
	}
}

void	ft_do_sudoku(char **argv)
{
	int		lin;
	int		col;

	lin = 1;
	while (lin <= 9)
	{
		while (argv[lin][col] != '\0')
		{
			if (argv[lin][col] == '0')
				ft_verif_column(argv, col);
		}
	}
 

}
