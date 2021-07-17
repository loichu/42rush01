/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:49:30 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/07/17 21:10:00 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	regle41(void)
{
	if(line[0] == 4 && line[5] == 1)
	{
		if(line[1] == 1 || line[1] == 0) 
		{
			line[1] = 1;
		}
		else 
		{
			return (false);
		}
		if(line[2] == 2 || line[2] == 0)
		{
			line[2] = 2;
		}
		else
		{
			return (false);
		}		
		if(line[3] == 3 || line[3] == 0)
		{
			line[3] = 3;
		}
		else
		{
			return (false);
		}
		if(line[4] == 4 || line[4] == 0)
		{
			line[4] = 4;
		}
		else
		{
			return (false);
		}
	}

}
