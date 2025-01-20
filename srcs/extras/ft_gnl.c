/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:18:35 by fclivaz           #+#    #+#             */
/*   Updated: 2025/01/20 20:22:01 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*gnlread(int fd, size_t len, char *raw, size_t rsize)
{
	char	buf[BUFFER_SIZE + 1];
	char	*ret;
	long	bytes;

	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes < 0)
		return (NULL);
	buf[bytes] = 0;
	ret = NULL;
	if (!(ft_strchr(buf, '\n') || bytes == 0))
		ret = gnlread(fd, len + bytes, NULL, rsize);
	if (ret == NULL)
	{
		ret = ft_calloc(len + rsize + bytes + 1, sizeof(char));
		if (ret == NULL)
			return (NULL);
	}
	ft_memcpy(&ret[len + rsize], buf, bytes);
	if (raw)
	{
		ft_memcpy(ret, raw, rsize);
		free(raw);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*keep[FOPEN_MAX];
	char		*ret;
	char		*pos;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!ft_strchr(keep[fd], '\n'))
		pos = gnlread(fd, 0, keep[fd], ft_strlen(keep[fd]));
	else
		pos = keep[fd];
	if (!pos || pos[0] == 0)
	{
		if (!pos)
			free(keep[fd]);
		else
			free(pos);
		return (keep[fd] = NULL);
	}
	ret = ft_substr(pos, 0, ft_strchr(pos, '\n') + 1 - pos);
	keep[fd] = ft_substr(ft_strchr(pos, '\n'), 1, ft_strlen(pos));
	free(pos);
	if (!ret || !keep[fd])
		return (NULL);
	return (ret);
}
