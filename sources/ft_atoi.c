/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:32:26 by bstablo           #+#    #+#             */
/*   Updated: 2023/06/10 15:16:46 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi(const char *str)
{
	int		n;
	long	nb;
	int		signe;

	n = 0;
	nb = 0;
	signe = 1;
	if (str[n] == '-' || str[n] == '+')
		if (str[n++] == '-')
			signe *= -1;
	if (str[n] < '0' || str[n] > '9')
		return (0);
	while (str[n] >= '0' && str[n] <= '9')
		nb = nb * 10 + (str[n++] - 48);
	if (str[n] != '\0')
		return (0);
	if (((signe * nb) > 2147483647 || (signe * nb) < -2147483648))
		ft_error();
	if (nb)
		return (nb * (int)signe);
	return (0);
}
