/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_22.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 10:06:41 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/07/18 16:14:40 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	regle32b(int *line)
{
	if (line[0] == 2 && line[5] == 3 && line[3] == 4)
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

char	regle22(int *line)
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

char	regle22_b(int *line)
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
