/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:05:53 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 22:05:01 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

int	**parse_args(char *arg);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	main(int argc, char **argv)
{
	int	**views;
	int	**grid;

	if (argc != 2 || ft_strlen(argv[1]) != 31)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	views = parse_args(argv[1]);
	if (!views)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	grid = ft_init_grid(views[0], views[1], views[2], views[3]);
	fill_grid(grid);
	ft_check_lines(grid);
	ft_complete(grid);
	ft_check_lines_deep(grid);
	print_grid(grid);
	return (0);
}

int	**parse_args(char *arg)
{
	int		nb;
	int		**views;
	int		i;
	int		j;
	char	space;

	views = (int **)malloc(4 * sizeof(int *));
	i = 0;
	j = 0;
	views[i] = (int *)malloc(4 * sizeof(int));
	while (*arg)
	{
		nb = (int)(*arg - '0');
		if (j != 0 && (j % 4) == 0 && *(arg - 1) == ' ')
		{
			views[++i] = (int *)malloc(4 * sizeof(int));
			j = 0;
		}
		if ((nb < 0 || nb > 9) && !(*arg == ' ' && *(arg - 1) != ' '))
			return (0);
		if (*arg != ' ')
			views[i][j++] = nb;
		arg++;
	}
	return (views);
}
