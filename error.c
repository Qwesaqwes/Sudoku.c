/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 22:55:06 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/12 23:16:14 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Check les arguments, si on a un erreur, on return 1 sinon 0
int		ft_check_error(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '.' || argv[i][j] == '/' || argv[i][j] > '9')
				return (1);
			j++;
		}
		if (j != 9)
			return (1);
		i++;
	}
	return (0);
}
