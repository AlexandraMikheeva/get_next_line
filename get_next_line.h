/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olydden <olydden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:54:08 by olydden           #+#    #+#             */
/*   Updated: 2020/08/02 03:17:41 by olydden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_copy(char *dest, char *src);
int		check_result(int read_bytes, char **storage, char **n);
void	ft_newstr(char *n, char **line, char **storage);
char	*check_storage(char *store, char **line);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free(char **s);

#endif
