/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:43:07 by jhermon-          #+#    #+#             */
/*   Updated: 2021/07/18 22:02:57 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "functions.h"

char	ft_complete(int **grid)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (!ft_check_flags(grid))
			return (0);
		print_grid(grid);
		grid = ft_rotate_grid(grid);
		print_grid(grid);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		grid = ft_rotate_grid(grid);
		i++;
	}
	return (1);
}

void	ft_complete_num(int **grid, char **flags, int num)
{
	int		i;
	int		j;
	int		k;
	int		line_found;
	char	found;

	i = 0;
	while (i < 4)
	{
		if (!flags[i][num - 1])
		{
			line_found = i + 1;
			j = 1;
			while (j < 5)
			{
				if (!ft_num_found(j, num, grid))
				{
					grid[line_found][j] = num;
				}
				j++;
			}
		}
		i++;
	}
}

char	ft_num_found(int j, int num, int **grid)
{
	int	k;

	k = 1;
	while (k < 5)
	{
		if (grid[k][j] == num)
		{
			return (1);
		}
		k++;
	}
	return (0);
}
