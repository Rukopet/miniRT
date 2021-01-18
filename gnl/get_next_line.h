/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:01:02 by egums             #+#    #+#             */
/*   Updated: 2021/01/12 20:01:03 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int		get_next_line(int fd, char **line);
int		ft_strlen_n(const char *s, char flag);
int		free_and_null(char **tmp, int flag);
int		ft_strchr_r(const char *s, int c);

# ifndef BUFFER
#  define BUFFER_SIZE 32
# endif

#endif