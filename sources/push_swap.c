/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:03:20 by bstablo           #+#    #+#             */
/*   Updated: 2023/06/10 15:06:59 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*s;

	if (argc < 2)
		return (0);
	s = arg(argc, argv);
	if (!s || ft_check_duplicate(s))
	{
		ft_free(&s);
		ft_error();
	}
	if (ft_need_sort(s))
		ft_sort(&s);
	ft_free(&s);
	return (0);
}
