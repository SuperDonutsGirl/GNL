/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:18:13 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/20 00:18:14 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	is_line(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*read_file(char *rest, int fd)
{
	char	*reading;
	int		rc;

	reading = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!reading)
		return (NULL);
	rc = 1;
	while (rc && !ft_strchr(rest, '\n'))
	{
		rc = read(fd, reading, BUFFER_SIZE);
		if (rc < 0)
			return (ft_free(reading));
		reading[rc] = '\0';
		rest = ft_strjoin(rest, reading);
	}
	ft_free(reading);
	return (rest);
}

char	*get_line(char *rest, size_t i)
{
	char	*line;
	size_t	y;

	if (rest[0] == '\0')
		return (NULL);
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	y = 0;
	while (rest[i] && rest[i] != '\n')
		line[y++] = rest[i++];
	if (rest[i] == '\n')
		line[y++] = rest[i];
	line[y] = '\0';
	return (line);
}

char	*recover_rest(char *rest, size_t i)
{
	char	*save;
	size_t	y;

	if (rest[0] == '\0')
		return (ft_free(rest));
	save = malloc(sizeof(char) * (ft_strlen(rest) - i) + 1);
	if (!save)
		return (NULL);
	y = 0;
	while (rest[i])
		save[y++] = rest[i++];
	save[y] = '\0';
	ft_free(rest);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	rest[fd] = read_file(rest[fd], fd);
	if (!rest[fd])
		return (NULL);
	line = get_line(rest[fd], is_line(rest[fd]));
	rest[fd] = recover_rest(rest[fd], is_line(rest[fd]));
	return (line);
}
/*
int main (void)
{
	int fd3;
	int fd4;
	char *line;

	fd3 = open("file", O_RDONLY);
	fd4 = open("lol", O_RDONLY);


	line = get_next_line(fd3);
	printf("ligne 1 : %s", line);

	line = get_next_line(fd4);
	printf("lignelol 1 : %s", line);
	
	line = get_next_line(fd3);
	printf("ligne 2 : %s", line);

	line = get_next_line(fd4);
	printf("lignelol 2 : %s", line);

	line = get_next_line(fd3);
	printf("ligne 3 : %s", line);

	line = get_next_line(fd4);
	printf("lignelol 3 : %s", line);
	
	line = get_next_line(fd3);
	printf("ligne 4 : %s", line);

	line = get_next_line(fd4);
	printf("lignelol 4 : %s", line);
	
	line = get_next_line(fd3);
	printf("ligne 5 : %s", line);

	line = get_next_line(fd4);
	printf("lignelol 5 : %s", line);
	
	line = get_next_line(fd3);
	printf("ligne 6 : %s", line);

	line = get_next_line(fd4);
	printf("lignelol 6 : %s", line);
	
	line = get_next_line(fd3);
	printf("ligne 7 : %s", line);

	line = get_next_line(fd4);
	printf("lignelol 7 : %s", line);
	
	

	close(fd4);
	close(fd3);
}*/