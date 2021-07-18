/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 04:54:05 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 05:01:24 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	**ft_rotate_grid(int **grid)
{
	int	**rot;
	int	i;
	int	j;

	rot = malloc(6 * sizeof(int*));
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

void	ft_free_grid(int **grid)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(rot[i]);
		i++;
	}
	free(rot);
}
