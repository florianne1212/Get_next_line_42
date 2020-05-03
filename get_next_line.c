/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:27:36 by fcoudert          #+#    #+#             */
/*   Updated: 2019/12/11 10:18:51 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_check_retour(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char				*debut(char *rest, char **line, int i)
{
	char			*tmp;

	if (i >= 0)
	{
		rest[i] = '\0';
		*line = ft_strdup(rest);
		tmp = ft_strdup(rest + (i + 1));
		free(rest);
		rest = NULL;
		rest = tmp;
		return (rest);
	}
	return (rest);
}

char				*last_line(char *rest, char **line, int i, int ret)
{
	char			*tmp;

	if (ret == 0 && i != -1)
	{
		rest[i] = '\0';
		*line = ft_strdup(rest);
		tmp = ft_strdup(rest + (i + 1));
		free(rest);
		rest = NULL;
		rest = tmp;
		free(tmp);
		tmp = NULL;
		return (rest);
	}
	else if (ret == 0)
	{
		*line = ft_strdup(rest);
		free(rest);
		rest = NULL;
		return (rest);
	}
	return (rest);
}

int					get_next_line(int fd, char **line)
{
	static char		*rest = NULL;
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	int				i;

	i = 0;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0 || i != -1)
	{
		buf[ret] = '\0';
		rest = ft_strjoin(rest, buf);
		i = ft_check_retour(rest);
		if (i >= 0)
			rest = debut(rest, line, i);
		if (i >= 0)
			return (1);
	}
	rest = last_line(rest, line, i, ret);
	if (ret == 0 && i != -1)
		return (1);
	else if (ret == 0)
		return (0);
	return (-1);
}
