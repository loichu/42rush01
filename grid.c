/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*      grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 04:54:05 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 21:51:34 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "functions.h"

void	ft_free_grid(int **grid)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	**ft_rotate_grid(int **grid)
{
	int	**rot;
	int	i;
	int	j;

	rot = malloc(6 * sizeof(int *));
	i = 0;
	while (i < 6)
	{
		rot[i] = malloc(6 * sizeof(int));
		j = 0;
		while (j < 6)
		{
			rot[i][j] = grid[5 - j][i];
			j++;
		}
		i++;
	}
	ft_free_grid(grid);
	return (rot);
}

void	fill_grid(int **grid)
{
	int	i;
	int	j;

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

int	**ft_allocate_grid(void)
{
	int	**grid;
	int	i;

	grid = malloc(6 * sizeof(int *));
	i = 0;
	while (i < 6)
	{
		grid[i] = malloc(6 * sizeof(int));
		i++;
	}
	return (grid);
}

int	**ft_init_grid(int *up, int *down, int *left, int *right)
{
	int	**grid;
	int	i;
	int	j;

	grid = ft_allocate_grid();
	i = -1;
	while (++i < 6)
	{
		grid[i] = malloc(6 * sizeof(int));
		j = -1;
		while (++j < 6)
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
		}
	}
	return (grid);
}
