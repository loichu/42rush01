/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_of_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:18:49 by jhermon-          #+#    #+#             */
/*   Updated: 2021/07/17 22:08:50 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	ft_rule_of_4(int *line)
{
	if (line[0] == 1) 
	{
		if (line[1] = 0 || line[1] = 4)
		{	
			line[1] = 4;
			return true;
		}
		else
			return false;
	}
   return true;	
}

t_bool ft_all_different(int *line)
{
	if (line[1] != line[2] && line[2] != line[3] && line[3] != line[4] && line[4] != line[1] && line[1] != line[3] && line[2] != line[4])
	{
		return true
	}
	else
	{
		return false
	}
}

t_bool ft_rule_of_3(int *line)
{
	if (line[0] == 3)
	{
		if (line[1] != 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int	ft_break_line_1(int *grid)
{
	int	i;
	int	j;
	int	l;
	int	compteur;

	l = 0;
	i = 0;
	j = 0;
	compteur = 1;
	
	while (compteur < 5)
	{

		while (l < 6)
		{	
			line[l] = grid[i][j];
			l++;
			j++;
		}
		return(line)
		compteur++;
		i++;
		l = 0;
		j = 0;
	}
}

int	ft_break_line_2(int *grid)
{
	int	i;
	int	j;
	int	l;
	int	compteur;

	l = 0;
	i = 5;
	j = 0;
	compteur = 1;
	while (compteur < 9)
	{

		while (l < 6)
		{
			line[l] = grid[i][j];
			l++;
			i--;
		}
		return(line)
		compteur++;
		j++;
		l = 0;
	}

int	ft_break_line_3(int *grid)
{
	int	i;
	int	j;
	int	l;
	int	compteur;

	l = 0;
	i = 4;
	j = 5;
	compteur = 1;
	while (compteur < 13)
	{

		while (l < 6)
		{
			line[l] = grid[i][j];
			l++;
			j--;
		}
		return(line)
		compteur++;
		i--;
		l = 0;
		j = 5;
	}

int	ft_break_line_4(int *grid)
{
	int	i;
	int	j;
	int	l;
	int	compteur;

	l = 0;
	i = 0;
	j = 4;
	compteur = 1;
	while (compteur < 17)
	{
		while (l < 6)
		{
			line[l] = grid[i][j];
			l++;
			i++;	
		}
		return(line)
		compteur++;
		j--;
		l = 0;
		i = 0;
	}	
}

int ft_missing_numbers(int *line)
{
	int	i;

	total = 10;
	i = 0;

	while (i < 5)
	{	
		total -= line[i];
		i++;
	}
	return (total);	
}

int	ft_croissant(int *line)
{
	if (line[0] > 2 && line[3] = 4)	
		
}
