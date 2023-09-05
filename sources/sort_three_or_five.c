/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_or_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:23:00 by bstablo           #+#    #+#             */
/*   Updated: 2023/06/11 18:55:57 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_five(t_stack **sta, t_stack **stb)
{
	if (ft_find_index(*sta, ft_min(*sta)) < 4)
		while (ft_min(*sta) != (*sta)->nbr)
			ft_rotate(sta, 0);
	else
		while (ft_min(*sta) != (*sta)->nbr)
			ft_reverse_rotate(sta, 0);
	ft_push(stb, sta, 1);
	if (ft_find_index(*sta, ft_min(*sta)) < 3)
		while (ft_min(*sta) != (*sta)->nbr)
			ft_rotate(sta, 0);
	else
		while (ft_min(*sta) != (*sta)->nbr)
			ft_reverse_rotate(sta, 0);
	ft_push(stb, sta, 1);
	if (!(ft_need_sort(*stb)))
		ft_swap(stb, 1);
}

void	ft_sort_three(t_stack **sta)
{
	if (ft_max(*sta) == (*sta)->nbr)
	{
		ft_rotate(sta, 0);
		if (ft_need_sort(*sta))
			ft_swap(sta, 0);
	}
	else if (ft_min(*sta) == (*sta)->nbr)
	{
		ft_reverse_rotate(sta, 0);
		ft_swap(sta, 0);
	}
	else
	{
		if (ft_find_index(*sta, ft_max(*sta)) == 1)
			ft_reverse_rotate(sta, 0);
		else
			ft_swap(sta, 0);
	}
}
