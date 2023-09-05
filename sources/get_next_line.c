/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:17:24 by bstablo           #+#    #+#             */
/*   Updated: 2023/05/11 18:17:53 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_go_to_next(char *stock)
{
	int		n;
	int		x;
	char	*next_l;

	n = 0;
	while (stock[n] && stock[n] != '\n')
		n++;
	if (stock[n] == '\0')
	{
		free(stock);
		return (NULL);
	}
	next_l = malloc(sizeof(char) * (ft_strlen(stock) - n + 1));
	if (next_l == NULL)
	{
		free(stock);
		return (NULL);
	}
	n++;
	x = 0;
	while (stock[n])
		next_l[x++] = stock[n++];
	next_l[x] = '\0';
	free(stock);
	return (next_l);
}

char	*ft_get_line(char *stock)
{
	int		n;
	char	*line;

	n = 0;
	if (!(stock[n]))
		return (NULL);
	while (stock[n] && stock[n] != '\n')
		n++;
	line = malloc(sizeof(char) * (n + 2));
	if (line == NULL)
		return (NULL);
	n = 0;
	while (stock[n] && stock[n] != '\n')
	{
		line[n] = stock[n];
		n++;
	}
	if (stock[n] == '\n')
	{
		line[n] = stock[n];
		n++;
	}
	line[n] = '\0';
	return (line);
}

char	*ft_read_to_next(char *stock, int fd)
{
	char	*buff;
	int		nbr_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL || read(fd, buff, 0) == -1)
	{
		if (buff)
			free(buff);
		return (NULL);
	}
	nbr_bytes = 1;
	while (nbr_bytes != 0 && (!ft_strchr(stock, '\n')))
	{
		nbr_bytes = read(fd, buff, BUFFER_SIZE);
		buff[nbr_bytes] = '\0';
		stock = ft_strjoin(stock, buff);
	}
	free(buff);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stock = ft_read_to_next(stock, fd);
	if (stock == NULL)
		return (NULL);
	line = ft_get_line(stock);
	stock = ft_go_to_next(stock);
	return (line);
}
