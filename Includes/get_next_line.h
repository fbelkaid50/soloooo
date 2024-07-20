/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:39:34 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/06/28 07:04:36 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_free(char **s1, char *s2);
char	*ft_read(char **stc, int fd, char *str);
char	*ft_addback(char *s1, char *s2);
int		line_check(char *str);
char	*ft_substr(char *s, int start, int len, int x);
int		ft_strlen(char *s);
char	*get_next_line(int fd);
#endif