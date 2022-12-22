/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:41:05 by amontalb          #+#    #+#             */
/*   Updated: 2022/11/28 16:45:09 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_end_lign(char *buf)
{
	int			i;

	i = 0;
	if (!buf)
		return (-1);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_read_line(char **temp, char **line, int fd, int i)
{
	char	buf[BUFFER_SIZE + 1];

	*line = ft_strjoin(*line, *temp);
	while (ft_end_lign(*line) == -1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= 0)
		{
			if (*temp)
				free(*temp);
			*temp = NULL;
			if (i == -1 || *line[0] == '\0')
				return (0);
			return (1);
		}	
		buf[i] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	if (ft_end_lign(*line) != -1)
	{	
		free(*temp);
		*temp = ft_strjoin(NULL, &(*line)[ft_end_lign(*line) + 1]);
		(*line)[ft_end_lign(*line) + 1] = '\0';
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*line;
	int			i;

	line = NULL;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
	{
		if (*temp)
			free (*temp);
		return (NULL);
	}
	i = ft_read_line(&temp[fd], &line, fd, 0);
	if (i == 0)
	{
		free (line);
		line = NULL;
	}
	return (line);
}
