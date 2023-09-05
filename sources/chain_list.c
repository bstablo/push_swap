/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:00:08 by bstablo           #+#    #+#             */
/*   Updated: 2023/05/11 17:44:44 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_add_back(t_stack **s, t_stack *n)
{
	if (!s)
		return ;
	if (!*s)
		*s = n;
	else
		(ft_last_list(*s))->next = n;
}

t_stack	*ft_stack_new(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error();
	new->nbr = n;
	new->next = NULL;
	return (new);
}

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = tmp;
	}
}
