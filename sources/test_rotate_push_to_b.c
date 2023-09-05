/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate_push_to_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:17:09 by bstablo           #+#    #+#             */
/*   Updated: 2023/05/11 17:57:33 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_test_rr_p2b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = ft_find_place_b(b, nbr);
	if (i < ft_find_index(a, nbr))
		i = ft_find_index(a, nbr);
	return (i);
}

int	ft_test_rrr_p2b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, nbr))
		i = ft_list_size(b) - ft_find_place_b(b, nbr);
	if ((i < (ft_list_size(a) - ft_find_index(a, nbr)))
		&& ft_find_index(a, nbr))
		i = ft_list_size(a) - ft_find_index(a, nbr);
	return (i);
}

int	ft_test_rarrb_p2b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, nbr))
		i = ft_list_size(b) - ft_find_place_b(b, nbr);
	i = i + ft_find_index(a, nbr);
	return (i);
}

int	ft_test_rrarb_p2b(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (ft_find_index(a, nbr))
		i = ft_list_size(a) - ft_find_index(a, nbr);
	i = i + ft_find_place_b(b, nbr);
	return (i);
}
