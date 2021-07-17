/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:10:50 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/17 19:16:10 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef enum e_bool {false, true} t_bool;

t_bool	rule32(int *line)
{
	if (line[0] == 3 && line[5] == 2)
	{
		if (line[3] == 0 || line[3] == 3)
		{
			line[3] = 3;
			return (true);
		}
		else
		{
			return (false);
		}
	}
	return (true);
}

void	print_grid(int **grid)
{
	int		i;
	int		j;
	char	nb;

	i = 0;
	while (i < 6)
	{
		if (i == 5)
			write(1, "-|----|-\n", 9);
		j = 0;
		while (j < 6)
		{
			if (j == 5)
				write(1, "|", 1);
			if (grid[i][j] == 0)
				nb = ' ';
			else
				nb = '0' + grid[i][j];
			write(1, &nb, 1);
			if (j == 0)
				write(1, "|", 1);
			j++;
		}
		if (i == 0)
			write(1, "\n-|----|-", 9);
		i++;
		write(1, "\n", 1);
	}
}

int	**build_grid(int *up, int *down, int *left, int *right)
{
	int	**grid;
	int i; // column
	int j; // line

	grid = malloc(6 * sizeof(int*));
	i = 0;
	while (i < 6)
	{
		grid[i] = malloc(6 * sizeof(int));
		grid[i][0] = left[i - 1];
		j = 0;
		while (j < 6)
		{
			if (i == 0)
				grid[i][j] = up[j];
			else if (i == 5)
				grid[i][j] = down[j];
			else if (j > 0 && j < 5)
				grid[i][j] = 0;
			j++;
		}
		if (i > 0 && i < 5)
			grid[i][5] = right[i - 1];
		i++;
	}
	return grid;
}

int	main(void)
{
	int	up[] = {0, 2, 2, 1, 3, 0};
	int	down[] = {0, 2, 2, 3, 1, 0};
	int	left[] = {3, 2, 1, 2};
	int	right[] = {2, 2, 3, 1};

	//while ()
	//{
	//	if (!rule32(&line))
	//	{
	//		write(1, "Error\n", 6);
	//		return (1);
	//	}
	//}

	int	**grid = build_grid(up, down, left, right);
	print_grid(grid);
	return (0);
}
