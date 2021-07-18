/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:05:53 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 15:11:53 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

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
	return (len--);
}

int	main(int argc, char **argv)
{
	int **views = parse_args(argv[1]);
	//int	up[] = {2, 2, 1, 3};
	//int	down[] = {2, 2, 3, 1};
	//int	left[] = {3, 2, 1, 2};
	//int	right[] = {2, 2, 3, 1};
	//printf("argc: %d\n", argc);
	//printf("argv: %s\n", argv[1]);

	if (argc != 2 || ft_strlen(argv[1]) != 31)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!views)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	//int	**grid = init_grid(up, down, left, right);
	int	**grid = init_grid(views[0], views[1], views[2], views[3]);
	printf("Builded grid:\n");
	print_grid(grid);
	ft_check_lines(grid);
	printf("\nApplied rules:\n");
	print_grid(grid);
	if (!ft_complete(grid))
		write(1, "Error\n", 6);
	printf("\nCompleted:\n");
	print_grid(grid);
	return (0);
}

int	**parse_args(char *arg)
{
	int	nb;
	int	**views;
	int	i;
	int	j;
	char	space;

	views = malloc(4 * sizeof(int*));
	i = 0;
	j = 0;
	space = 0;
	views[i] = malloc(4 * sizeof(int));
	while (*arg)
	{
		nb = *arg - '0';
		if (j != 0 && j % 4 == 0 && !space)
		{
			i++;
			views[i] = malloc(4 * sizeof(int));
			j = 0;
		}
		if (nb < 0 || nb > 9)
		{
			if (!(*arg == ' ' && space))
				return (0);
		}
		else
		{
			views[i][j] = nb;
			j++;
		}
		arg++;
		space = !space;
	}
	return (views);
}
