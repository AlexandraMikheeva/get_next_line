/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olydden <olydden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 18:02:37 by olydden           #+#    #+#             */
/*   Updated: 2020/08/02 03:17:55 by olydden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	char	*d;

	len = ft_strlen(s) + 1;
	dup = (char *)malloc(len);
	if (dup == NULL)
		return (NULL);
	d = dup;
	while (*s)
		*dup++ = *s++;
	*dup = *s;
	return (d);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (*s++ != '\0')
			i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*ss;

	i = 0;
	ss = (char *)s;
	while (i < ft_strlen(s))
	{
		if (c == ss[i])
			return (&(ss[i]));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		len1;
	int		len2;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(*newstr) * (len1 + len2 + 1));
	if (newstr == NULL)
		return (NULL);
	while (*s1)
		newstr[i++] = *s1++;
	while (*s2)
		newstr[i++] = *s2++;
	newstr[i] = '\0';
	return (newstr);
}

void	ft_free(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}
