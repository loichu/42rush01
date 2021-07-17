/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:49:30 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/07/17 17:17:28 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	regle41(void)
{
	if(grid[0] == 4 && grid[5] == 1)
	{
		if(grid[1] == 1 || grid[1] == 0) 
		{
			grid[1] = 1;
		}
		else 
		{
			return (false);
		}
		if(grid[2] == 2 || grid[2] == 0)
		{
			grid[2] = 2;
		}
		else
		{
			return (false);
		}		
		if(grid[3] == 3 || grid[3] == 0)
		{
			grid[3] = 3;
		}
		else
		{
			return (false);
		}
		if(grid[4] == 4 || grid[4] == 0)
		{
			grid[4] = 4;
		}
		else
		{
			return (false);
		}
	}

}
