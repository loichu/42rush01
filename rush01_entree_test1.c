/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_entree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:48:34 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/07/17 21:09:31 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
t_bool	test1(int **tab_test1);
t_bool	test4(int **tab_test1);

t_bool fill_tab_test(char **argv )

{
	int	tab_test [4][4]
	int l;
	int c;
	
	l = 0;
	c = 0;
	p = 0;
	while (l < 4)
	{
		while (c < 4)
		{
			tab_test[l][c] = argv[1][p]
			c++;
			p = p + 2;
		}
		c = 0;
		l++;
	}
	l = 0;
	c = 0;
	test1(tab_test, l, c);
	l = 0;
	c = 0;
	test4(tab_test, l, c);

}


t_bool	test1(int **tab_test1, int l, int c)
{
	int t;
	t = 0;

	while (c < 4)
	{
		while (l < 4)
		{
			if(tab_test1[l][c] == 1)
			{
				t++;
				l++;
			}
			else
			{
				l++;
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
	c++
	t = 0;
	}
}

t_bool	test4(int **tab_test1)
{
	int t;
	t = 0;

	while (c < 4)
	{
		while (l < 4)
		{
			if(tab_test1[l][c] == 4)
			{
				t++;
				l++;
			}
			else
			{
				l++;
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
	c++
	t = 0;
	}
}
