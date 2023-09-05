/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:09:23 by bstablo           #+#    #+#             */
/*   Updated: 2023/05/11 18:18:36 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_read_to_next(char *stock, int fd);
char	*ft_get_line(char *stock);
char	*ft_go_to_next(char	*stock);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *stock, char *buff);
char	*ft_strchr(char *str, int n);

#endif
