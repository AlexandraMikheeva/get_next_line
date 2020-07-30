/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olydden <olydden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:54:08 by olydden           #+#    #+#             */
/*   Updated: 2020/07/30 11:27:19 by olydden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	GET_NEXT_LINE_H
# define 	GET_NEXT_LINE_H

#include <unistd.h> //NULL
#include <fcntl.h> //open
#include <stdlib.h> //malloc
#include <stdio.h>

int 	get_next_line(int fd, char **line);
int		check_storage(char **store, char **line);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_strclr(char *s);
char	*ft_strnew(size_t size);
void	ft_free(char *s);

#endif
