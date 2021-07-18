/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:00:21 by jhermon-          #+#    #+#             */
/*   Updated: 2021/07/18 20:41:55 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_init_count(void)
{
	int	*count;
	int	i;

	count = malloc(4 * sizeof(int));
	i = 0;
	while (i < 4)
	{
		count[i] = 0;
		i++;
	}
	return (count);
}

int	*ft_count_nums(char **flags)
{
	int	*count;
	int	i;
	int	j;

	count = ft_init_count();
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
	return (count);
}
