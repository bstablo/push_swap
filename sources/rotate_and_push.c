/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:38:27 by bstablo           #+#    #+#             */
/*   Updated: 2023/05/11 17:44:13 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_rr(t_stack **a, t_stack **b, int nbr, int n)
{
	if (n == 0)
	{
		while ((*a)->nbr != nbr && ft_find_place_b(*b, nbr) > 0)
		{
			ft_rotate(a, 2);
			ft_rotate(b, 3);
		}
		while ((*a)->nbr != nbr)
			ft_rotate(a, 0);
		while (ft_find_place_b(*b, nbr) > 0)
			ft_rotate(b, 1);
		ft_push(b, a, 1);
		return (-1);
	}
	while ((*b)->nbr != nbr && ft_find_place_a(*a, nbr) > 0)
	{
		ft_rotate(a, 2);
		ft_rotate(b, 3);
	}
	while ((*b)->nbr != nbr)
		ft_rotate(b, 1);
	while (ft_find_place_a(*a, nbr) > 0)
		ft_rotate(a, 0);
	ft_push(a, b, 0);
	return (-1);
}

int	ft_rrr(t_stack **a, t_stack **b, int nbr, int n)
{
	if (n == 0)
	{
		while ((*a)->nbr != nbr && ft_find_place_b(*b, nbr) > 0)
		{
			ft_reverse_rotate(a, 2);
			ft_reverse_rotate(b, 3);
		}
		while ((*a)->nbr != nbr)
			ft_reverse_rotate(a, 0);
		while (ft_find_place_b(*b, nbr) > 0)
			ft_reverse_rotate(b, 1);
		ft_push(b, a, 1);
		return (-1);
	}
	while ((*b)->nbr != nbr && ft_find_place_a(*a, nbr) > 0)
	{
		ft_reverse_rotate(a, 2);
		ft_reverse_rotate(b, 3);
	}
	while ((*b)->nbr != nbr)
		ft_reverse_rotate(b, 1);
	while (ft_find_place_a(*a, nbr) > 0)
		ft_reverse_rotate(a, 0);
	ft_push(a, b, 0);
	return (-1);
}

int	ft_rarrb(t_stack **a, t_stack **b, int nbr, int n)
{
	if (n == 0)
	{
		while ((*a)->nbr != nbr)
			ft_rotate(a, 0);
		while (ft_find_place_b(*b, nbr) > 0)
			ft_reverse_rotate(b, 1);
		ft_push(b, a, 1);
	}
	else
	{
		while ((*b)->nbr != nbr)
			ft_reverse_rotate(b, 1);
		while (ft_find_place_a(*a, nbr) > 0)
			ft_rotate(a, 0);
		ft_push(a, b, 0);
	}
	return (-1);
}

int	ft_rrarb(t_stack **a, t_stack **b, int nbr, int n)
{
	if (n == 0)
	{
		while ((*a)->nbr != nbr)
			ft_reverse_rotate(a, 0);
		while (ft_find_place_b(*b, nbr) > 0)
			ft_rotate(b, 1);
		ft_push(b, a, 1);
	}
	else
	{
		while ((*b)->nbr != nbr)
			ft_rotate(b, 1);
		while (ft_find_place_a(*a, nbr) > 0)
			ft_reverse_rotate(a, 0);
		ft_push(a, b, 0);
	}
	return (-1);
}
