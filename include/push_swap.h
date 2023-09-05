/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:20:04 by bstablo           #+#    #+#             */
/*   Updated: 2023/06/10 16:21:49 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
}t_stack;

t_stack	*ft_last_list(t_stack *s);
void	ft_error(void);
int		ft_atoi(const char *str);
void	ft_add_back(t_stack **s, t_stack *n);
t_stack	*ft_stack_new(int n);
void	ft_free(t_stack **lst);
int		ft_check_duplicate(t_stack *s);
int		ft_need_sort(t_stack *s);
void	ft_sort_three(t_stack **sta);
void	ft_sort_five(t_stack **sta, t_stack **stb);
t_stack	*ft_last_list(t_stack *s);
int		ft_list_size(t_stack *s);
int		ft_min(t_stack *s);
int		ft_max(t_stack *s);
t_stack	*get_list_from_one_arg(char **argv);
t_stack	*get_list_from_args(int argc, char **argv);
t_stack	*arg(int argc, char **argv);
void	ft_sort_b_3_remaining(t_stack **sta, t_stack **stb);
t_stack	*ft_sort_b(t_stack **sta);
t_stack	**ft_sort_a(t_stack **sta, t_stack **stb);
void	ft_sort(t_stack **sta);
void	ft_swap(t_stack **s, int x);
void	ft_push(t_stack **s, t_stack **s2, int x);
void	ft_rotate(t_stack **s, int x);
void	ft_reverse_rotate(t_stack **s, int x);
char	*ft_copy(char const *str, char c, size_t *nb_word);
char	**ft_split(char const *s, char c);
int		ft_find_place_a(t_stack *a, int nbr);
int		ft_find_place_b(t_stack *b, int nbr);
int		ft_find_index(t_stack *s, int nbr);
int		ft_rotate_type_p2a(t_stack *a, t_stack *b);
int		ft_test_rr_p2a(t_stack *a, t_stack *b, int nbr);
int		ft_test_rrr_p2a(t_stack *a, t_stack *b, int nbr);
int		ft_test_rarrb_p2a(t_stack *a, t_stack *b, int nbr);
int		ft_test_rrarb_p2a(t_stack *a, t_stack *b, int nbr);
int		ft_rotate_type_p2b(t_stack *a, t_stack *b);
int		ft_test_rr_p2b(t_stack *a, t_stack *b, int nbr);
int		ft_test_rrr_p2b(t_stack *a, t_stack *b, int nbr);
int		ft_test_rrarb_p2b(t_stack *a, t_stack *b, int nbr);
int		ft_test_rarrb_p2b(t_stack *a, t_stack *b, int nbr);
int		ft_rr(t_stack **a, t_stack **b, int nbr, int n);
int		ft_rrr(t_stack **a, t_stack **b, int nbr, int n);
int		ft_rarrb(t_stack **a, t_stack **b, int nbr, int n);
int		ft_rrarb(t_stack **a, t_stack **b, int nbr, int n);
void	ft_is_good_character(int argc, char **argv);
char	*ft_check(t_stack **a, t_stack **b, char *line);
void	ft_check2(t_stack **a, t_stack **b, char *line);
void	ft_checker_line(t_stack **a, t_stack **b, char *line);

#endif