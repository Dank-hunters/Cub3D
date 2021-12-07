/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:54:47 by cguiot            #+#    #+#             */
/*   Updated: 2021/08/20 07:46:20 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strrlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		c;
	char	*d;

	i = 0;
	c = 0;
	if (!s1 && !s2)
		return (NULL);
	d = malloc(sizeof(char) * (ft_strrlen(s1) + ft_strrlen(s2) + 1));
	if (d == NULL)
		return (0);
	while (s1 && s1[c])
		d[i++] = s1[c++];
	c = 0;
	while (s2 && s2[c])
	{
		d[i] = s2[c++];
		i++;
	}
	if (s1)
		free((char *)s1);
	s1 = NULL;
	d[i] = 0;
	return (d);
}

char	*ft_strdup(const char *s1, int leaks)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	str = (char *)malloc(sizeof(char) * ft_strrlen(s1) + 1);
	if (str == NULL)
	{
		if (leaks == 1)
			free((char *)s1);
		return (NULL);
	}
	str[0] = '\0';
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	if (leaks == 1)
	{
		free((char *)s1);
		s1 = NULL;
	}
	return (str);
}
