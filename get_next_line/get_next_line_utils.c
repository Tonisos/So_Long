/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontalb <amontalb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:41:07 by amontalb          #+#    #+#             */
/*   Updated: 2022/12/22 08:56:13 by amontalb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*join;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	join = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
	{
		free (join);
		return (NULL);
	}
	while (s1 != NULL && s1[j])
	{
			join[i++] = s1[j++];
	}
	j = 0;
	while (s2 != NULL && s2[j])
	{	
		join[i++] = s2[j++];
	}
	join[i] = '\0';
	if (s1)
		free (s1);
	return (join);
}
