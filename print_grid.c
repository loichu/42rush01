/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:57:19 by jhermon-          #+#    #+#             */
/*   Updated: 2021/07/18 20:37:40 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_grid(int **grid)
{
	int		i;
	int		j;
	char	nb;

	i = 0;
	while (i < 6)
	{
		if (i == 5)
			write(1, "--|---------|--\n", 16);
		j = 0;
		while (j < 6)
		{
			if (j == 5)
				write(1, "| ", 2);
			if (grid[i][j] == 0)
				nb = 'x';
			else
				nb = '0' + grid[i][j];
			write(1, &nb, 1);
			if (j == 0)
				write(1, " | ", 3);
			else
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		if (i == 0)
			write(1, "--|---------|--\n", 16);
		i++;
	}
}
