/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:42:32 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/07/22 23:06:30 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/get_next_line.h"

char	*ft_free(char **s1, char *s2)
{
	free(*s1);
	*s1 = NULL;
	free(s2);
	return (NULL);
}

char	*ft_read(char **stc, int fd, char *str)
{
	ssize_t	bytesread;
	int		plc;
	char	*ret;

	bytesread = 1;
	ret = NULL;
	while (bytesread > 0)
	{
		bytesread = read(fd, str, BUFFER_SIZE);
		if (bytesread == -1)
			return (ft_free(stc, str));
		str[bytesread] = '\0';
		*stc = ft_addback(*stc, str);
		plc = line_check(*stc);
		if (plc != -1)
		{
			ret = ft_substr(*stc, 0, plc, 0);
			*stc = ft_substr(*stc, plc + 1, ft_strlen(*stc), 1);
			free(str);
			return (ret);
		}
	}
	ret = ft_substr(*stc, 0, ft_strlen(*stc), 0);
	ft_free(stc, str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*stc;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	return (ft_read(&stc, fd, buff));
}
