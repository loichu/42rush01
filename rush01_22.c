/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_22.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 10:06:41 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/07/18 15:13:20 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	regle22(void)
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
	return (1);
}