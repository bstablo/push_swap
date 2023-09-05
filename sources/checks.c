/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:43:59 by bstablo           #+#    #+#             */
/*   Updated: 2023/05/11 17:47:34 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_duplicate(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s->next;
		while (tmp)
		{
			if (s->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		s = s->next;
	}
	return (0);
}

int	ft_need_sort(t_stack *s)
{
	int	n;

	n = s->nbr;
	while (s)
	{
		if (n > s->nbr)
			return (1);
		n = s->nbr;
		s = s->next;
	}
	return (0);
}

void	ft_is_good_character(int argc, char **argv)
{
	int	n;
	int	x;

	n = 0;
	x = 1;
	while (x < argc)
	{
		n = 0;
		while (argv[x][n])
		{
			if (argv[x][n] == '-' && (n == 0 || argv[x][n - 1] == ' ') &&
			argv[x][n + 1] >= '0' && argv[x][n + 1] <= '9')
			n++;
			else if ((argv[x][n] < '0' || argv[x][n] > '9') &&
			argv[x][n] != ' ')
				ft_error();
			else
				n++;
		}
		x++;
	}
}
