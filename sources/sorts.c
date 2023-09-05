/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:15:15 by bstablo           #+#    #+#             */
/*   Updated: 2023/05/11 17:51:53 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stack **s, int x)
{
	int		n;
	t_stack	*s2;

	n = (*s)->nbr;
	s2 = (*s)->next;
	(*s)->nbr = s2->nbr;
	s2->nbr = n;
	if (x == 0)
		write(1, "sa\n", 3);
	if (x == 1)
		write(1, "sb\n", 3);
	if (x == 2)
		write(1, "ss\n", 3);
}

void	ft_push(t_stack **s, t_stack **s2, int x)
{
	t_stack	*tmp;

	if (!s2)
		return ;
	tmp = *s;
	*s = *s2;
	*s2 = (*s2)->next;
	(*s)->next = tmp;
	if (x == 0)
		write(1, "pa\n", 3);
	if (x == 1)
		write(1, "pb\n", 3);
}

void	ft_rotate(t_stack **s, int x)
{
	t_stack	*tmp;

	if (!*s || !(*s)->next)
		return ;
	tmp = *s;
	*s = ft_last_list(*s);
	(*s)->next = tmp;
	*s = tmp->next;
	tmp->next = NULL;
	if (x == 0)
		write(1, "ra\n", 3);
	if (x == 1)
		write(1, "rb\n", 3);
	if (x == 2)
		write(1, "rr\n", 3);
}

void	ft_reverse_rotate(t_stack **s, int x)
{
	t_stack	*tmp;
	int		n;

	if (!*s || !(*s)->next)
		return ;
	n = 0;
	tmp = *s;
	while ((*s)->next)
	{
		*s = (*s)->next;
		n++;
	}
	(*s)->next = tmp;
	while (n-- > 1)
		tmp = tmp->next;
	tmp->next = NULL;
	if (x == 0)
		write(1, "rra\n", 4);
	if (x == 1)
		write(1, "rrb\n", 4);
	if (x == 2)
		write(1, "rrr\n", 4);
}
