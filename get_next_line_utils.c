/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:21:47 by fcoudert          #+#    #+#             */
/*   Updated: 2019/12/11 10:12:56 by fcoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_strlen(char *str)
{
	size_t			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(const char *s1)
{
	int				size_s1;
	char			*copy;
	int				i;

	i = 0;
	size_s1 = ft_strlen((char *)s1);
	if (!(copy = malloc(sizeof(char) * (size_s1 + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	size_t			ss1;
	size_t			ss2;
	char			*s3;

	i = 0;
	j = 0;
	if (s1 == NULL)
		ss1 = 0;
	else
		ss1 = ft_strlen((char *)s1);
	ss2 = ft_strlen((char *)s2);
	if (!(s3 = malloc(sizeof(char) * (ss1 + ss2 + 1))))
		return (0);
	while (i < (ss1))
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < (ss2))
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free((char *)s1);
	return (s3);
}
