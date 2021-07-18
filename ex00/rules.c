/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 04:15:55 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 20:40:34 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	ft_rule32(int *line)
{
	if (line[0] == 3 && line[5] == 2)
	{
		if (line[3] == 0 || line[3] == 4)
			line[3] = 4;
		else
			return (0);
	}
	return (1);
}

char	ft_rule1(int *line)
{
	if (line[0] == 1)
	{
		if (line[1] == 0 || line[1] == 4)
			line[1] = 4;
		else
			return (0);
	}
	return (1);
}

char	ft_rule12(int *line)
{
	if (line[0] == 1 && line[5] == 2)
	{
		if ((line[1] == 4 || line[1] == 0) && (line[4] == 3 || line[4] == 0))
		{
			line[1] = 4;
			line[4] = 3;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

char	ft_rule4(int *line)
{
	if (line[0] == 4)
	{
		if (line[1] == 1 || line[1] == 0)
			line[1] = 1;
		else
			return (0);
		if (line[2] == 2 || line[2] == 0)
			line[2] = 2;
		else
			return (0);
		if (line[3] == 3 || line[3] == 0)
			line[3] = 3;
		else
			return (0);
		if (line[4] == 4 || line[4] == 0)
			line[4] = 4;
		else
			return (0);
	}
	return (1);
}
