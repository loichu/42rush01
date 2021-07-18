/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:03:28 by jhermon-          #+#    #+#             */
/*   Updated: 2021/07/18 20:48:26 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "functions.h"

char	ft_check_flags(int **grid)
{
	int		i;
	int		j;
	char	**flags;
	int		*count;

	flags = ft_set_flags(grid);
	if (!flags)
		return (0);
	count = ft_count_nums(flags);
	j = 0;
	while (j < 4)
	{
		if (count[j] == 3)
			ft_complete_num(grid, flags, j + 1);
		j++;
	}
	free(count);
	ft_free_flags(flags);
	return (1);
}

char	**ft_set_flags(int **grid)
{
	int		i;
	int		j;
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
			}
			j++;
		}
		i++;
	}
	return (flags);
}

char	**ft_init_flags(void)
{
	int		i;
	int		j;
	char	**flags;

	flags = malloc(4 * sizeof(char *));
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
