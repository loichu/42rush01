/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 04:29:20 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 20:43:57 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "functions.h"

char	ft_check_rules(int *line)
{
	if (!ft_rule4(line))
		return (0);
	if (!ft_rule1(line))
		return (0);
	if (!ft_rule32(line))
		return (0);
	if (!ft_rule12(line))
		return (0);
	return (1);
}

char	ft_check_lines(int **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 1;
		while (j < 5)
		{
			if (!ft_check_rules(grid[j]))
				return (0);
			j++;
		}
		grid = ft_rotate_grid(grid);
		i++;
	}
	return (1);
}
