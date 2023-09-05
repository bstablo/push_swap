/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:13:02 by bstablo           #+#    #+#             */
/*   Updated: 2023/05/11 17:48:31 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_last_list(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

int	ft_list_size(t_stack *s)
{
	int	n;

	n = 0;
	while (s)
	{
		s = s->next;
		n++;
	}
	return (n);
}

int	ft_min(t_stack *s)
{
	int	n;

	n = s->nbr;
	while (s)
	{
		if (s->nbr < n)
			n = s->nbr;
		s = s->next;
	}
	return (n);
}

int	ft_max(t_stack *s)
{
	int	n;

	n = s->nbr;
	while (s)
	{
		if (s->nbr > n)
			n = s->nbr;
		s = s->next;
	}
	return (n);
}
