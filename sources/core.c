/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:02:45 by bstablo           #+#    #+#             */
/*   Updated: 2023/06/10 15:12:46 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_list_from_one_arg(char **argv)
{
	t_stack	*s;
	char	**tab;
	int		x;
	int		n;

	s = NULL;
	x = 1;
	n = -1;
	tab = ft_split(argv[1], ' ');
	if (!tab)
		ft_error();
	while (tab[++n])
	{
		x = ft_atoi(tab[n]);
		ft_add_back(&s, ft_stack_new(x));
	}
	if (tab == NULL)
		ft_error();
	if (n < 2)
		exit(0);
	while (--n >= 0)
		free(tab[n]);
	free(tab);
	return (s);
}

t_stack	*get_list_from_args(int argc, char **argv)
{
	t_stack	*s;
	int		x;
	int		n;

	s = NULL;
	x = 0;
	n = 1;
	while (n < argc)
	{
		x = ft_atoi(argv[n++]);
		ft_add_back(&s, ft_stack_new(x));
	}
	return (s);
}

t_stack	*arg(int argc, char **argv)
{
	t_stack	*s;

	ft_is_good_character(argc, argv);
	if (argc == 2)
		s = get_list_from_one_arg(argv);
	else
		s = get_list_from_args(argc, argv);
	return (s);
}
