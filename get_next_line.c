/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sothomas <sothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:57:45 by sothomas          #+#    #+#             */
/*   Updated: 2020/03/06 11:33:59 by sothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read(int *fd, char **tmp, char *buf)
{
	char		*ptemp;
	ssize_t		ret;

	while (!ft_strchr(*tmp, '\n'))
	{
		if ((ret = read(*fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		if (ret == 0)
			break ;
		ptemp = *tmp;
		*tmp = ft_strjoin(ptemp, buf);
		free(ptemp);
	}
	return (1);
}

static int		ft_dispatch(char **tmp, char **line)
{
	char	*ptemp;

	if (ft_strchr(*tmp, '\n'))
	{
		*line = ft_strcdup(*tmp, '\n');
		ptemp = *tmp;
		*tmp = ft_strcdup((ft_strchr(*tmp, '\n') + 1), '\0');
		free(ptemp);
		return (1);
	}
	else
	{
		*line = *tmp;
		*tmp = NULL;
		return (0);
	}
}

static int		ft_return(int i, char **line, char *ptemp)
{
	if (i)
		return (1);
	else
	{
		if (!*line)
			*line = ft_strcdup("\0", 0);
		else
		{
			ptemp = ft_strjoin(*line, "\0");
			free(*line);
			*line = ft_strcdup(ptemp, 0);
		}
		free(ptemp);
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			i;
	static char	*tmp;
	char		*ptemp;

	i = 0;
	ptemp = NULL;
	if (!tmp)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * 1)))
			return (-1);
		tmp[i] = '\0';
	}
	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (ft_read(&fd, &tmp, buf) == -1)
		return (-1);
	i = ft_dispatch(&tmp, line);
	return (ft_return(i, line, ptemp));
}
