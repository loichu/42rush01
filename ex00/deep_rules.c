/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:41:11 by jhermon-          #+#    #+#             */
/*   Updated: 2021/07/18 20:41:26 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rule32b(int *line)
{
	if (line[0] == 3 && line[5] == 2 && line[3] == 4)
	{
		if (line[1] == 0 && line[2] == 0)
		{
			if (line[4] == 3)
			{
				line[1] = 1;
				line[2] = 2;
			}
			else if (line[4] == 2)
			{
				line[1] = 1;
				line[2] = 3;
			}
			else if (line[4] == 1)
			{
				line[1] = 2;
				line[2] = 3;
			}
		}
	}
}

void	ft_rule32c(int *line)
{
	if (line[0] == 3 && line[5] == 2 && line[3] == 4)
	{
		if (line[2] == 0 && line[4] == 0)
		{
			if (line[1] == 2)
			{
				line[2] = 3;
				line[4] = 1;
			}
		}
		if (line[1] == 0 && line[4] == 0)
		{
			if (line[2] == 2)
			{
				line[1] = 1;
				line[4] = 3;
			}
		}
	}
}

void	ft_rule22(int *line)
{
	if (line[0] == 2 && line[5] == 2 && line[3] == 4)
	{
		if (line[1] == 0 && line[2] == 0)
		{
			if (line[4] == 3)
			{
				line[1] = 2;
				line[2] = 1;
			}
			else if (line[4] == 2)
			{
				line[1] = 3;
				line[2] = 1;
			}
			else if (line[4] == 1)
			{
				line[1] = 3;
				line[2] = 2;
			}
		}
	}
}

void	ft_rule22_b(int *line)
{
	if (line[0] == 2 && line[5] == 2 && line[3] == 4)
	{
		if ((line[1] == 0 || line[1] == 3) && (line[4] == 0 || line[4] == 1))
		{
			if (line[2] == 2)
			{
				line[1] = 3;
				line[4] = 1;
			}
		}
		if ((line[2] == 0 || line[2] == 1) && (line[4] == 0 || line[4] == 3))
		{
			if (line[1] == 2)
			{
				line[2] = 1;
				line[4] = 3;
			}
		}
	}
}
