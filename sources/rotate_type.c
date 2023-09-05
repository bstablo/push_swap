/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:54:26 by bstablo           #+#    #+#             */
/*   Updated: 2023/05/11 17:49:31 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_rotate_type_p2b(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = ft_test_rrr_p2b(a, b, a->nbr);
	while (tmp)
	{
		if (i > ft_test_rr_p2b(a, b, tmp->nbr))
			i = ft_test_rr_p2b(a, b, tmp->nbr);
		if (i > ft_test_rrr_p2b(a, b, tmp->nbr))
			i = ft_test_rrr_p2b(a, b, tmp->nbr);
		if (i > ft_test_rarrb_p2b(a, b, tmp->nbr))
			i = ft_test_rarrb_p2b(a, b, tmp->nbr);
		if (i > ft_test_rrarb_p2b(a, b, tmp->nbr))
			i = ft_test_rrarb_p2b(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

int	ft_rotate_type_p2a(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = ft_test_rrr_p2a(a, b, b->nbr);
	while (tmp)
	{
		if (i > ft_test_rr_p2a(a, b, tmp->nbr))
			i = ft_test_rr_p2a(a, b, tmp->nbr);
		if (i > ft_test_rrr_p2a(a, b, tmp->nbr))
			i = ft_test_rrr_p2a(a, b, tmp->nbr);
		if (i > ft_test_rarrb_p2a(a, b, tmp->nbr))
			i = ft_test_rarrb_p2a(a, b, tmp->nbr);
		if (i > ft_test_rrarb_p2a(a, b, tmp->nbr))
			i = ft_test_rrarb_p2a(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
