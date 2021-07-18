/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 07:35:33 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 08:46:06 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**ft_rotate_grid(int **grid);
void	ft_free_grid(int **grid);
void	print_grid(int **grid);
void	fill_grid(int **grid);
int	**init_grid(int *up, int *down, int *left, int *right);
