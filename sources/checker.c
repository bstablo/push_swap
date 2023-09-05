/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:39:17 by bstablo           #+#    #+#             */
/*   Updated: 2023/06/11 19:04:59 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_check(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n'
		&& ft_list_size(*a) > 1)
		ft_swap(a, 3);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n'
		&& ft_list_size(*b) > 1)
		ft_swap(b, 3);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n'
		&& ft_list_size(*a) > 1 && ft_list_size(*b) > 1)
	{
		ft_swap(a, 3);
		ft_swap(b, 3);
	}
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n'
		&& ft_list_size(*b) > 0)
		ft_push(a, b, 3);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n'
		&& ft_list_size(*a) > 0)
		ft_push(b, a, 3);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n'
		&& ft_list_size(*a) > 0)
		ft_rotate(a, 3);
	else
		ft_check2(a, b, line);
	return (get_next_line(0));
}

void	ft_check2(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n'
		&& ft_list_size(*b) > 0)
		ft_rotate(b, 3);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n'
		&& ft_list_size(*a) > 0 && ft_list_size(*b) > 0)
	{
		ft_rotate(a, 3);
		ft_rotate(b, 3);
	}
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r'
		&& line[3] == '\n' && ft_list_size(*a) > 0 && ft_list_size(*b) > 0)
	{
		ft_reverse_rotate(a, 3);
		ft_reverse_rotate(b, 3);
	}
	else if (line[0] == 'r' && line[1] == 'r'
		&& line[2] == 'a' && line[3] == '\n' && ft_list_size(*a) > 0)
		ft_reverse_rotate(a, 3);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b'
		&& line[3] == '\n' && ft_list_size(*b) > 0)
		ft_reverse_rotate(b, 3);
	else
		ft_error();
}

void	ft_checker_line(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(a, b, line);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (ft_need_sort(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	b = NULL;
	a = arg(argc, argv);
	if (!a || ft_check_duplicate(a))
	{
		ft_free (&a);
		ft_error();
	}
	line = get_next_line(0);
	if (!line && ft_need_sort(a))
		write(1, "KO\n", 3);
	else if (!line && !ft_need_sort(a))
		write(1, "OK\n", 3);
	else
		ft_checker_line(&a, &b, line);
	ft_free(&b);
	ft_free(&a);
	return (0);
}
