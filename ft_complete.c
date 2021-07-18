/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 05:15:49 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 07:23:57 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	ft_complete(char **grid)
{
	int	i;

	// Look for completion on both sides
	i = 0;
	while (i < 2)
	{
		if (!ft_check_flags(grid))
			return (false);
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
	return (true);
}

t_bool	ft_check_flags(char **grid)
{
	int i;
	int j;
	t_bool	**flags;
	int	count[4];

	flags = ft_set_flags(grid);
	if (!flags)
		return false;
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
	return true;
}

void	ft_complete_num(char **grid, t_bool **flags, int num)
{
	int i;
	int j;
	int line_found;
	t_bool	found;

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
						found = true;
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

t_bool	**ft_set_flags(char **grid)
{
	int	i;
	int	j;
	t_bool	**flags;

	flags = init_flags();
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
					flags[i][grid[i][j] - 1] = true;
			}
			j++;
		}
		i++;
	}
}

t_bool	**ft_init_flags(void)
{
	int	i;
	int	j;
	t_bool	**flags;

	flags = malloc(4 * sizeof(t_bool*));
	i = 0;
	while (i < 4)
	{
		flags[i] = malloc(4 * sizeof(t_bool));
		j = 0;
		while (i < 4)
		{
			flags[i][j] = false;
		}
	}
	return (flags);
}

void	ft_free_flags(t_bool *flags)
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
