/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:10:50 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 07:24:36 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>


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

void	fill_grid(int **grid)
{
	int i;
	int j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	**init_grid(int *up, int *down, int *left, int *right)
{
	int	**grid;
	int i;
	int j;

	grid = malloc(6 * sizeof(int*));
	i = 0;
	while (i < 6)
	{
		grid[i] = malloc(6 * sizeof(int));
		j = 0;
		while (j < 6)
		{
			if ((i == 0 || i == 5) && (j == 0 || j == 5))
				grid[i][j] = 0;
			else if (i == 0)
				grid[i][j] = up[j - 1];
			else if (i == 5)
				grid[i][j] = down[j - 1];
			else if (j == 0)
				grid[i][j] = left[i - 1];
			else if (j == 5)
				grid[i][j] = right[i - 1];
			j++;
		}
		i++;
	}
	fill_grid(grid);
	return (grid);
}

