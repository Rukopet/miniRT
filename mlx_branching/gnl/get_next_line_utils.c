/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:59:56 by egums             #+#    #+#             */
/*   Updated: 2021/01/12 20:00:09 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int			ft_strchr_r(const char *s, int c)
{
	int		index;

	index = 0;
	if (!s)
		return (0);
	while (s[index] != 0)
	{
		if (s[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char		*ft_strjoin_g(const char *s1, const char *s2)
{
	int		sum_len;
	char	*ret;
	char	*dst;

	if (NULL == s1)
		return (ft_strdup(s2));
	sum_len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (sum_len + 1));
	if (NULL == ret)
		return (NULL);
	dst = ret;
	while (*s1)
		*dst++ = *s1++;
	*dst++ = '\0';
	ft_strlcat(ret, s2, sum_len + 1);
	return (ret);
}
