/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_entree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:48:34 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/07/17 19:58:42 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool enter_test1(char )

{
	int up[4];
	int down[4];
	int left[4];
	int right[4];
	int t;
	int i;

	t = 0;
	i = 0;
	while (i < 4)
	{
		if(up[i] == 1)
		{
			t++;
			i++;
		}
		else
		{
			i++;
		}
	}
	if(t != 1)
	{
		return (false);
	}
	else
	{
		return (true);
	}

	while (i < 4)
	{
		if(up[i] == 4)
		{
			t++;
			i++;
		}
		else
		{
			i++;
		}
	}
	if(t > 1)
	{
		return (false);
	}
	else
	{
		return (true);
	}
}

