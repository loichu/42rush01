/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 05:15:49 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 15:36:15 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
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
		write(1, "\n\n", 2);
		//printf("%d\n", )
		print_grid(grid);
		ft_rotate_grid(grid);
		write(1, "\n\n", 2);
		print_grid(grid);
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

int	*ft_init_count(void)
{
	int	*count;
	int	i;

	count = malloc(4 * sizeof(int));
	i = 0;
	while (i < 4)
	{
		count[i] = 0;
		i++;
	}
	return (count);
}

int	*ft_count_nums(char **flags)
{
	int	*count;
	int i;
	int j;

	count = ft_init_count();
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
	return (count);
}

char	ft_check_flags(int **grid)
{
	int i;
	int j;
	char	**flags;
	int	*count;

	flags = ft_set_flags(grid);
	if (!flags)
	{
		printf("flag error");
		return (0);
	}
	count = ft_count_nums(flags);
	//write(1, "set flags", 9);
	//printf("\n%d\t%d\t%d\t%d", count[0], count[1], count[2], count[3]);
	j = 0;
	while (j < 4)
	{
		if (count[j] == 3)
			ft_complete_num(grid, flags, j + 1);
		j++;
	}
	free(count);
	ft_free_flags(flags);
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
			line_found = i + 1;
			j = 1;
			while (j < 5)
			{
				found = 0;
				// Iterate by column
				i = 1;
				while (i < 5)
				{
					//printf("\nline: %d\tcol: %d\tval: %d", i, j, grid[i][j]);
					if (grid[i][j] == num)
					{
						found = 1;
						break;
					}
					i++;
				}
				if (!found)
				{
					//printf("found %d", grid[line_found][j]);
					grid[line_found][j] = num;
				}
				j++;
			}
		}
		else
		{
			i++;
		}
	}
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
				if (flags[i][grid[i + 1][j + 1] - 1] == 1)
					return (0);
				else
					flags[i][grid[i + 1][j + 1] - 1] = 1;
				//printf("\n%d\n", grid[i + 1][j + 1]);
			}
			j++;
		}
		i++;
	}
	//write(1, "flags", 5);
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
		while (j < 4)
		{
			flags[i][j] = 0;
			j++;
		}
		i++;
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
