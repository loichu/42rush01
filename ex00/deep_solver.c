/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:26:10 by jhermon-          #+#    #+#             */
/*   Updated: 2021/07/18 22:14:27 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "functions.h"
#include <stdlib.h>

void	ft_check_deep_rules(int *line)
{
	ft_rule32b(line);
	ft_rule22(line);
	ft_rule22_b(line);
	ft_rule32c(line);
}

int	*ft_count_numbers(int **grid)
{
	char	**flags;
	int		*count;

	flags = ft_set_flags(grid);
	if (!flags)
	{
		return (0);
	}
	count = ft_count_nums(flags);
	ft_free_flags(flags);
	return (count);
}

char	ft_check_deep_rules_count(int **grid, int *count)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 1;
		while (j < 5)
		{
			ft_check_deep_rules(grid[j]);
			j++;
		}
		grid = ft_rotate_grid(grid);
		i++;
	}
	count = ft_count_numbers(grid);
	if (!ft_complete(grid) || !count)
		return (0);
	return (1);
}

char	ft_check_lines_deep(int **grid)
{
	int		i;
	int		j;
	int		*count;

	count = ft_count_numbers(grid);
	while (count[0] < 4 || count[1] < 4 || count[2] < 4 || count[3] < 4)
	{
		ft_check_deep_rules_count(grid, count);
		count = ft_count_numbers(grid);
	}
	free(count);
	return (1);
}
