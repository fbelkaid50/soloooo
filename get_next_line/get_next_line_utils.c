/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:55:30 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/07/22 23:07:48 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/get_next_line.h"

char	*ft_substr(char *s, int start, int len, int x)
{
	char	*p;
	int		i;

	if (start > len)
		return (NULL);
	p = malloc((len - start + 2) * sizeof(char));
	if (!p)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (start <= len)
		p[i++] = s[start++];
	if (x == 1)
		free(s);
	p[i] = '\0';
	if (p[0] == '\0')
	{
		free(p);
		return (NULL);
	}
	return (p);
}

int	line_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_addback(char *s1, char *s2)
{
	char	*ret;
	int		i;

	i = -1;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	ret = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i])
		ret[i] = s1[i];
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = '\0';
	free(s1);
	return (ret);
}
