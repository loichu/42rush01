/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 04:29:20 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 05:15:18 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	ft_check_lines(char **grid)
{
	int	i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 1;
		while (j < 5)
		{
			if (!ft_check_rules(grid[j]))
				return (false);
			j++;
		}
		grid = ft_rotate_grid(grid);
		i++;
	}
	return (true);
}

t_bool	ft_check_rules(char *line)
{
	if (!ft_rule4(line))
		return (false);
	if (!ft_rule1(line))
		return (false);
	if (!ft_rule32(line))
		return (false);
	if (!ft_rule12(line))
		return (false);
	return (true);
}
