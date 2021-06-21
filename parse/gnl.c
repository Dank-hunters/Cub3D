/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:08:40 by cguiot            #+#    #+#             */
/*   Updated: 2021/06/21 16:22:57 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_joinone(char *line, char c)
{
	int		len;
	char	*temp;
	int		i;

	i = 0;
	len = ft_strlen(line);
	temp = malloc(sizeof(char) * len + 2);
	if (temp == NULL)
		return (NULL);
	while (i != len)
	{
		temp[i] = line[i];
		i++;
	}
	if (line != NULL)
		free(line);
	line = NULL;
	if (c != '\n')
		temp[i] = c;
	else
		temp[i] = '\0';
	temp[i + 1] = '\0';
	return (temp);
}

int	gnl(int fd, char **line)
{
	int		ret;
	int		i;
	char	buff[1];

	i = 0;
	ret = 1;
	*line = NULL;
	*line = malloc(sizeof(char) * 2);
	if (line == NULL)
		return (-1);
	line[0][0] = 0;
	line[0][1] = 0;
	while (ret == 1 || ret == EOF)
	{
		ret = read(fd, buff, 1);
		*line = ft_joinone(*line, *buff);
		if (buff[0] == '\n')
			return (ret);
		i++;
	}
	return (ret);
}
