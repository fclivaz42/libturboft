/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:27:34 by fclivaz           #+#    #+#             */
/*   Updated: 2023/11/28 18:45:46 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_gnljoin(char *s1, char *s2)
{
	int		i;
	int		diff;
	char	*ret;

	i = -1;
	diff = -1;
	if (s1 == NULL)
		s1 = (char *)ft_calloc(1, 1);
	if (!s1 || !s2)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	ret = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	while (s1[++diff] != 0)
		ret[diff] = s1[diff];
	while (s2[++i] != 0)
		ret[diff + i] = s2[i];
	ret[diff + i] = 0;
	free(s1);
	return (ret);
}

static char	*ft_copy(char **s, const char *end)
{
	int		x;
	int		delta;
	char	*ret;
	char	*tmp;

	x = -1;
	tmp = *s;
	delta = (char *)end - (char *)tmp;
	ret = ft_calloc(delta + 1, sizeof(char));
	while (tmp[++x] && tmp[x] != '\n')
		ret[x] = tmp[x];
	if (tmp[x] == '\n')
		ret[x] = '\n';
	tmp = ft_strdup(end);
	if (!tmp)
		return (NULL);
	free(*s);
	*s = tmp;
	return (ret);
}

static char	*gnl_copy(int fd, char *raw)
{
	char	*buf;
	ssize_t	bytes;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (!ft_strchr(raw, '\n') && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes < 0)
		{
			free(raw);
			free(buf);
			return (NULL);
		}
		buf[bytes] = 0;
		raw = ft_gnljoin(raw, buf);
	}
	free(buf);
	return (raw);
}

char	*get_next_line(int fd)
{
	static char		*stat;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stat = gnl_copy(fd, stat);
	if (!stat)
		return (NULL);
	if (stat[0] == 0)
	{
		free(stat);
		stat = NULL;
		return (NULL);
	}
	tmp = ft_strchr(stat, '\n');
	if (!tmp)
	{
		tmp = ft_strdup(stat);
		free(stat);
		stat = NULL;
		return (tmp);
	}
	++tmp;
	return (ft_copy(&stat, tmp));
}
