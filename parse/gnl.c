/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:08:40 by cguiot            #+#    #+#             */
/*   Updated: 2021/04/27 15:07:43 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char *ft_joinone(char *line, char c)
{
	int len;
	char *temp;
	int i;

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
	free(line);
	line = NULL;
	if (c != '\n')
		temp[i] = c;
	else 
		temp[i] = '\0';
	temp[i + 1] = '\0';
	return (temp);
}


int gnl(int fd, char **line)
{
	int ret;
	int i;
	char buff[1];

	i = 0;
	ret = 1;
	*line = NULL;
	*line = malloc(sizeof(char) * 2);
	line[0][0] = 0;
	line[0][1] = 0;
	while (ret == 1)
	{
		ret = read(fd, buff, 1);
		*line = ft_joinone(*line, *buff); 
		if (buff[0] == '\n')
			return(ret);
		i++;
	}
	return (ret);
}
