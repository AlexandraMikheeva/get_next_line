/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olydden <olydden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:52:22 by olydden           #+#    #+#             */
/*   Updated: 2020/07/30 11:27:16 by olydden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_storage(char **store, char **line)
{
	char *endofline;

	if (*store)
	{
		printf("goose");
		if ((endofline = ft_strchr(*store, '\n')))
		{
			if (*(++endofline) == '\0')
			{
				*line = ft_strdup(--endofline);
				ft_free(*store);
				return (1);
			}
			*(--endofline) = '\0';
			printf("STORE1: %s%c\n", *store, '$');
			*line = ft_strdup(*store);
			printf("L: %s%c\n", *line, '$');
			*store += (ft_strlen(*store) + 1);
			printf("STORE2: %s%c\n", *store, '$');
			printf("LINE AFTER STORAGE: %s%c\n", *line, '$');
			return (1);
		}
		else
		{
			*line = ft_strdup(*store);
			ft_free(*store);
			// return (1);
			printf("LINE AFTER STORAGE: %s%c\n", *line, '$');
		}
	}
	else
	{
		printf("goose");
		*line = ft_strdup("\0");
		ft_free(*store);
		printf("LINE AFTER STORAGE: %s%c\n", *line, '$');
	}
	return (0);
}

int get_next_line(int fd, char **line)
{
	char 			line_util[BUFFER_SIZE + 1];
	char 			*endof_line;
	static char		*storage;
	int 			read_bytes;
	
	// printf("blabla");
	printf("Storage: %s%c\n", storage, '$');
	if (check_storage(&storage, line))
		return (1);
	printf("FIRST LINE: %s%c\n", *line, '$');
	while((read_bytes = read(fd, line_util, BUFFER_SIZE)))
	{
		if (read_bytes < 0)
			return (-1);
		line_util[read_bytes] = '\0';
		printf("READ_BYTES1: %d\n", read_bytes);
		printf("LINE_UTIL1: %s%c\n", line_util, '$');
		if ((endof_line = ft_strchr(line_util, '\n')))
		{
			*endof_line = '\0';
			if(!(*line = ft_strjoin(*line, line_util)))
				return (-1);
			printf("LINE: %s%c\n", *line, '$');
			storage = ft_strdup(++endof_line);
			printf("STORAGE: %s%c\n", storage, '$');
			break;
		}
		if (!(*line = ft_strjoin(*line, line_util)))
			return (-1);
		printf("LINE AFTER JOIN: %s%c\n", *line, '$');
	}
	printf("READ_BYTES2: %d\n", read_bytes);
	if (read_bytes || ft_strlen(*line) || ft_strlen(storage))
	{
		// printf("LEN_LINE: %ld\nLEN_STORAGE: %ld\n", ft_strlen(*line), ft_strlen(storage));
		return (1);
	}
	else
		return (0);
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

	// printf("RETURN: %d\n", get_next_line(fd, &line));
	// printf("FINAL LINE: %s\n\n", line);

	// printf("RETURN: %d\n", get_next_line(fd, &line));
	// printf("FINAL LINE: %s\n\n", line);

	// printf("RETURN: %d\n", get_next_line(fd, &line));
	// printf("FINAL LINE: %s\n\n", line);

	// printf("RETURN: %d\n", get_next_line(fd, &line));
	// printf("FINAL LINE: %s\n\n", line);

	return (0);
}