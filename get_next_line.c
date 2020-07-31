/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olydden <olydden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:52:22 by olydden           #+#    #+#             */
/*   Updated: 2020/07/31 13:41:46 by olydden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				ft_free(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

char				*ft_copy(char *dest, char *src)
{
	if (dest && src)
	{
		while (*src)
		{
			*dest++ = *src++;
		}
		*dest = '\0';
	}
	return (dest);
}

int					check_result(int read_bytes, char *storage, char **line)
{
	if (read_bytes || ft_strlen(*line) || ft_strlen(storage))
		return (1);
	else
	{
		if (storage)
		{
			free(storage);
			storage = NULL;
		}
		return (0);
	}
}

char				*check_storage(char *store, char **line)
{
	char			*str;

	str = NULL;
	if (store)
	{
		if ((str = ft_strchr(store, '\n')))
		{
			*str = '\0';
			*line = ft_strdup(store);
			ft_copy(store, ++str);
		}
		else
		{
			*line = ft_strdup(store);
			if (store)
			{
				while (*store)
					*store++ = '\0';
			}
		}
	}
	else
		*line = ft_strdup("\0");
	return (str);
}

int					get_next_line(int fd, char **line)
{
	char			line_util[BUFFER_SIZE + 1];
	char			*n;
	static char		*storage;
	int				read_bytes;
	char			*temp;

	n = check_storage(storage, line);
	while (!n && (read_bytes = read(fd, line_util, BUFFER_SIZE)))
	{
		if (read_bytes < 0 || fd < 0 || BUFFER_SIZE < 1)
			return (-1);
		line_util[read_bytes] = '\0';
		if ((n = ft_strchr(line_util, '\n')))
		{
			*n = '\0';
			if (!(storage = ft_strdup(++n)))
				return (-1);
		}
		temp = *line;
		if (!(*line = ft_strjoin(*line, line_util)))
			return (-1);
		ft_free(temp);
	}
	return (check_result(read_bytes, storage, line));
}

int main(void)
{
	char	*line;
	int		fd;

	fd = open("normal", O_RDONLY);
	// get_next_line(fd, &line);

	// get_next_line(fd, &line);
		
	while(get_next_line(fd, &line))
	{
		// printf("RETURN: %d\n", get_next_line(fd, &line));
		printf("\n\nFINAL LINE: %s%c\n\n", line, '$');
	}
	printf("\n\nFINAL LINE: %s%c\n\n", line, '$');

	// printf("RETURN: %d%c\n", get_next_line(fd, &line), '$');
	// printf("FINAL LINE: %n%c\n\n", line, '$');

	// printf("RETURN: %d%c\n", get_next_line(fd, &line), '$');
	// printf("FINAL LINE: %n%c\n\n", line, '$');

	// printf("RETURN: %d%c\n", get_next_line(fd, &line), '$');
	// printf("FINAL LINE: %n%c\n\n", line, '$');

	// printf("RETURN: %d%c\n", get_next_line(fd, &line), '$');
	// printf("FINAL LINE: %n%c\n\n", line, '$');

	return (0);
}
