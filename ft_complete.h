/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 07:42:13 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 09:37:23 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_complete(int **grid);
char	ft_check_flags(int **grid);
void	ft_complete_num(int **grid, char **flags, int num);
int	*ft_init_count(void);
char	**ft_set_flags(int **grid);
char	**ft_init_flags(void);
void	ft_free_flags(char **flags);
