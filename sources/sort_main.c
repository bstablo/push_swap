/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:31:21 by bstablo           #+#    #+#             */
/*   Updated: 2023/06/10 16:26:03 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_b_3_remaining(t_stack **sta, t_stack **stb)
{
	int		i;
	t_stack	*tmp;

	while (ft_list_size(*sta) > 3 && ft_need_sort(*sta))
	{
		tmp = *sta;
		i = ft_rotate_type_p2b(*sta, *stb);
		while (i >= 0)
		{
			if (i == ft_test_rr_p2b(*sta, *stb, tmp->nbr))
				i = ft_rr(sta, stb, tmp->nbr, 0);
			else if (i == ft_test_rrr_p2b(*sta, *stb, tmp->nbr))
				i = ft_rrr(sta, stb, tmp->nbr, 0);
			else if (i == ft_test_rarrb_p2b(*sta, *stb, tmp->nbr))
				i = ft_rarrb(sta, stb, tmp->nbr, 0);
			else if (i == ft_test_rrarb_p2b(*sta, *stb, tmp->nbr))
				i = ft_rrarb(sta, stb, tmp->nbr, 0);
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*ft_sort_b(t_stack **sta)
{
	t_stack	*stb;

	stb = NULL;
	if (ft_list_size(*sta) > 3 && ft_list_size(*sta) != 5 && ft_need_sort(*sta))
		ft_push(&stb, sta, 1);
	if (ft_list_size(*sta) > 3 && ft_list_size(*sta) != 5 && ft_need_sort(*sta))
		ft_push(&stb, sta, 1);
	if (ft_list_size(*sta) == 5 && ft_need_sort(*sta))
		ft_sort_five(sta, &stb);
	else if (ft_list_size(*sta) > 3 && ft_need_sort(*sta))
		ft_sort_b_3_remaining(sta, &stb);
	if (ft_need_sort(*sta))
		ft_sort_three(sta);
	return (stb);
}

t_stack	**ft_sort_a(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;
	int		i;

	while (*stb)
	{
		tmp = *stb;
		i = ft_rotate_type_p2a(*sta, *stb);
		while (i >= 0)
		{
			if (i == ft_test_rr_p2a(*sta, *stb, tmp->nbr))
				i = ft_rrr(sta, stb, tmp->nbr, 1);
			else if (i == ft_test_rrr_p2a(*sta, *stb, tmp->nbr))
				i = ft_rrr(sta, stb, tmp->nbr, 1);
			else if (i == ft_test_rarrb_p2a(*sta, *stb, tmp->nbr))
				i = ft_rarrb(sta, stb, tmp->nbr, 1);
			else if (i == ft_test_rrarb_p2a(*sta, *stb, tmp->nbr))
				i = ft_rrarb(sta, stb, tmp->nbr, 1);
			else
				tmp = tmp->next;
		}
	}
	return (sta);
}

void	ft_sort(t_stack **sta)
{
	t_stack	*stb;
	int		i;

	stb = NULL;
	if (ft_list_size(*sta) == 2)
		ft_swap(sta, 0);
	else
	{
		stb = ft_sort_b(sta);
		sta = ft_sort_a(sta, &stb);
		i = ft_find_index(*sta, ft_min(*sta));
		if (i < ft_list_size(*sta) - i)
		{
			while ((*sta)->nbr != ft_min(*sta))
				ft_rotate(sta, 0);
		}
		else
		{
			while ((*sta)->nbr != ft_min(*sta))
				ft_reverse_rotate(sta, 0);
		}
	}
}
