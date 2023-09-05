/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:29:29 by bstablo           #+#    #+#             */
/*   Updated: 2023/05/11 18:20:32 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_strjoin(char *stock, char *buff)
{
	size_t	n;
	size_t	x;
	size_t	len;
	char	*str;

	if (!stock)
	{
		stock = malloc(1);
		stock[0] = '\0';
	}
	len = ft_strlen(stock) + ft_strlen(buff);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	n = -1;
	x = 0;
	if (stock)
		while (stock[++n])
			str[n] = stock[n];
	while (buff[x])
		str[n++] = buff[x++];
	free(stock);
	return (str);
}

size_t	ft_strlen(char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strchr(char *str, int n)
{
	int	cpt;

	cpt = 0;
	if (!str)
		return (NULL);
	while (str[cpt])
	{
		if (str[cpt] == (char) n)
			return ((char *)str + cpt);
		cpt++;
	}
	if (str[cpt] == (char) n)
		return ((char *)str + cpt);
	return (NULL);
}
