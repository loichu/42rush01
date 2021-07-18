/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 05:15:49 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 09:38:14 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "main.h"

char	ft_complete(int **grid)
{
	int	i;

	// Look for completion on both sides
	i = 0;
	while (i < 2)
	{
		if (!ft_check_flags(grid))
			return (0);
		ft_rotate_grid(grid);
		i++;
	}
	// Put the grid back in the correct position
	i = 0;
	while (i < 2)
	{
		ft_rotate_grid(grid);
		i++;
	}
	return (1);
}

char	ft_check_flags(int **grid)
{
	int i;
	int j;
	char	**flags;
	int	count[4];

	flags = ft_set_flags(grid);
	if (!flags)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (flags[i][j])
				count[j]++; 
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 4)
	{
		if (count[j] == 3)
			ft_complete_num(grid, flags, j + 1);
		j++;
	}
	ft_free_flags(flags);
	free(count);
	return (0);
}

void	ft_complete_num(int **grid, char **flags, int num)
{
	int i;
	int j;
	int line_found;
	char	found;

	i = 0;
	while (i < 4)
	{
		// Search line without num
		if (!flags[i][num - 1])
		{
			line_found = i;
			j = 0;
			while (j < 4)
			{
				// Iterate by column
				i = 0;
				while (i < 4)
				{
					if (grid[i][j] == num)
					{
						found = 1;
						break;
					}
					i++;
				}
				if (!found)
					grid[line_found][j] = num;
				j++;
			}
		}
		i++;
	}
}

int	*ft_init_count(void)
{
	int	i;
	int	*count;

	count = malloc(4 * sizeof(int));
	i = 0;
	while (i < 4)
	{
		count[i] = 0;
		i++;
	}
	return count;
}

char	**ft_set_flags(int **grid)
{
	int	i;
	int	j;
	char	**flags;

	flags = ft_init_flags();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (grid[i + 1][j + 1] != 0)
			{
				if (flags[i][grid[i][j] - 1])
					return (0);
				else
					flags[i][grid[i][j] - 1] = 1;
			}
			j++;
		}
		i++;
	}
	return (flags);
}

char	**ft_init_flags(void)
{
	int	i;
	int	j;
	char	**flags;

	flags = malloc(4 * sizeof(char*));
	i = 0;
	while (i < 4)
	{
		flags[i] = malloc(4 * sizeof(char));
		j = 0;
		while (i < 4)
		{
			flags[i][j] = 0;
		}
	}
	return (flags);
}

void	ft_free_flags(char **flags)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(flags[i]);
		i++;
	}
	free(flags);
}
