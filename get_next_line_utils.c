/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sothomas <sothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 21:19:07 by sothomas          #+#    #+#             */
/*   Updated: 2020/03/06 11:31:09 by sothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char *tmp, char *buf)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!tmp || !buf)
		return (NULL);
	if (!(result = (char*)malloc(sizeof(result) * (ft_strlen(tmp) +
						ft_strlen(buf) + 1))))
		return (NULL);
	while (tmp[i])
	{
		result[i] = tmp[i];
		i++;
	}
	while (buf[j])
		result[i++] = buf[j++];
	result[i] = '\0';
	return (result);
}

char		*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	if ((char)c == '\0')
		return (&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char		*ft_strcdup(char *tmp, char c)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = ft_strlen(tmp);
	if (!(result = (char*)malloc(sizeof(*result) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		result[i] = 0;
		i++;
	}
	i = 0;
	while (tmp[i] && tmp[i] != c)
	{
		result[i] = tmp[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
