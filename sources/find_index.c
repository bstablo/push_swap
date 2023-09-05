/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:00:04 by bstablo           #+#    #+#             */
/*   Updated: 2023/05/11 17:40:30 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_index(t_stack *s, int nbr)
{
	int	i;

	i = 0;
	while (s->nbr != nbr)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	ft_find_place_b(t_stack *b, int nbr)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr > b->nbr && nbr < ft_last_list(b)->nbr)
		i = 0;
	else if (nbr > ft_max(b) || nbr < ft_min(b))
		i = ft_find_index(b, ft_max(b));
	else
	{
		tmp = b->next;
		while (b->nbr < nbr || tmp->nbr > nbr)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_place_a(t_stack *a, int nbr)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr < a->nbr && nbr > ft_last_list(a)->nbr)
		i = 0;
	else if (nbr > ft_max(a) || nbr < ft_min(a))
		i = ft_find_index(a, ft_min(a));
	else
	{
		tmp = a->next;
		while (a->nbr > nbr || tmp->nbr < nbr)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}
