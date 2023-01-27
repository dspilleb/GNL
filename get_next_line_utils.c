/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:03:52 by dspilleb          #+#    #+#             */
/*   Updated: 2023/01/27 18:07:04 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	a;

	a = 0;
	while (src[a])
		a++;
	if (size <= 0)
		return (a);
	i = 0;
	while (src[i] && size - 1 > i)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (a);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		end_s1;
	size_t		end_s2;
	char		*str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	end_s1 = ft_strlen(s1);
	end_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (end_s1 + end_s2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, end_s1 + 1);
	while (i < end_s2)
	{
		str[end_s1 + i] = s2[i];
		i++;
	}
	str[end_s1 + i] = '\0';
	return (str);
}

char	*extract(char *str)
{
	char		*line;
	size_t		i;
	size_t		len;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	len = i + 1;
	line = malloc(sizeof(char) * len + 1);
	if (!line)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_cleaner(char *tmp)
{
	size_t		i;
	size_t		len;
	char		*new_stock;

	i = 0;
	len = 0;
	if (!tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	len = ft_strlen(tmp) - i
	new_stock = malloc(sizeof(char) * (len + 1));
	if (!new_stock)
		return (NULL);
	len = 0;
	while (tmp[i + 1 + len])
	{
		new_stock[len] = tmp[i + 1 + len];
		i++;
	}
	new_stock[len] = '\0';
	free(tmp);
	return (new_stock);
}
