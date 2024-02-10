/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeziane <ymeziane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:55:41 by ymeziane          #+#    #+#             */
/*   Updated: 2023/11/06 16:22:59 by ymeziane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *str, char const *buff)
{
	size_t	total_len;
	char	*result;
	int		i;

	if (!buff)
		return (NULL);
	total_len = ft_strlen(str) + ft_strlen(buff);
	result = (char *)malloc(total_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
		result[i++] = *str++;
	str -= i;
	while (*buff)
		result[i++] = *buff++;
	result[i] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!c)
		return ((char *)s);
	return (NULL);
}
