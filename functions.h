/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 07:28:29 by lhumbert          #+#    #+#             */
/*   Updated: 2021/07/18 20:58:12 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FUNCTIONS_H
# define FUNCTIONS_H

char	ft_check_rules(int *line);
char	ft_check_lines(int **grid);
void	ft_check_deep_rules(int *line);
int		*ft_count_numbers(int **grid);
char	ft_check_deep_rules_count(int **grid, int *count);
char	ft_check_lines_deep(int **grid);
char	ft_complete(int **grid);
char	ft_check_flags(int **grid);
void	ft_complete_num(int **grid, char **flags, int num);
int		*ft_init_count(void);
char	**ft_set_flags(int **grid);
char	**ft_init_flags(void);
void	ft_free_flags(char **flags);
int		*ft_count_nums(char **flags);
char	ft_num_found(int j, int num, int **grid);
int		**ft_rotate_grid(int **grid);
void	ft_free_grid(int **grid);
void	print_grid(int **grid);
void	fill_grid(int **grid);
int		**init_grid(int *up, int *down, int *left, int *right);
void	ft_rule32b(int *line);
void	ft_rule22(int *line);
void	ft_rule22_b(int *line);
char	ft_check_lines_deep(int **grid);
int		**ft_init_grid(int *up, int *down, int *left, int *right);
void	ft_rule32c(int *line);
char	ft_rule32(int *line);
char	ft_rule1(int *line);
char	ft_rule12(int *line);
char	ft_rule4(int *line);

#endif	/* FUNCTIONS_H */
