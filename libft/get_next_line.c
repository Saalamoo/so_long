/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:02:43 by saalamoo          #+#    #+#             */
/*   Updated: 2023/06/04 18:12:03 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line_read_everything(int fd, char *buf, char *tmp, char *b3d)
{
	char	*last;
	int		i;

	if (b3d)
	{
		tmp = ft_strdup(b3d);
		free(b3d);
	}
	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		last = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = ft_strdup(last);
		free(last);
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	return (tmp);
}

char	*caller(int fd, char *gnl, char *buf)
{
	char		*tmp;
	static char	*b3d;
	int			j;

	tmp = NULL;
	if (!b3d)
		tmp = ft_strdup("");
	tmp = new_line_read_everything(fd, buf, tmp, b3d);
	j = -1;
	while (tmp[++j])
	{
		if (tmp[j] == '\n')
			break ;
	}
	b3d = ft_substr(tmp, j + 1, ft_strlen(tmp) - j - 1);
	gnl = ft_substr(tmp, 0, j + 1);
	if (tmp != NULL)
		free(tmp);
	if (b3d && ft_strlen(gnl) == 0)
	{
		free(b3d);
		b3d = NULL;
	}
	return (gnl);
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*gnl;

	if (fd < 0 || BUFFER_SIZE > 16711568 || BUFFER_SIZE <= 0 || fd > INT_MAX)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (0);
	gnl = NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	gnl = caller(fd, gnl, buf);
	free(buf);
	if (!gnl || gnl == NULL || gnl[0] == '\0')
	{
		if (gnl)
			free(gnl);
		return (0);
	}
	return (gnl);
}
