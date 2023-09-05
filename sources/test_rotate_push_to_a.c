/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate_push_to_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:57:07 by bstablo           #+#    #+#             */
/*   Updated: 2023/05/11 17:57:20 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_test_rr_p2a(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = ft_find_place_a(a, nbr);
	if (i < ft_find_index(b, nbr))
		i = ft_find_index(b, nbr);
	return (i);
}

int	ft_test_rrr_p2a(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, nbr))
		i = ft_list_size(a) - ft_find_place_a(a, nbr);
	if ((i < (ft_list_size(b) - ft_find_index(b, nbr)))
		&& ft_find_index(b, nbr))
		i = ft_list_size(b) - ft_find_index(b, nbr);
	return (i);
}

int	ft_test_rrarb_p2a(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, nbr))
		i = ft_list_size(a) - ft_find_place_a(a, nbr);
	i = i + ft_find_index(b, nbr);
	return (i);
}

int	ft_test_rarrb_p2a(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_index(b, nbr))
		i = ft_list_size(b) - ft_find_index(b, nbr);
	i = i + ft_find_place_a(a, nbr);
	return (i);
}
