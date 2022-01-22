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

#include "get_next_line.h"
#include <stdio.h>

char*get_line(int fd, cahr *line, char **rest)
{
	char	*reading;
	char	*save
}
char	*get_next_line(int fd)
{
	char		*line;
	static char	rest[OPEN_MAX][BUFFER_SIZE];

	line = NULL;
	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	return(get_line(fd, line, rest[fd]));
}

int main (void)
{
	int fd3;
	int fd4;
	char *line;

	fd3 = open("file", O_RDONLY);
	fd4 = open("lol", O_RDONLY);




	line = get_next_line(fd);
	printf("ligne 1 : %s", line);
	
	line = get_next_line(fd);
	printf("ligne 2 : %s", line);

	line = get_next_line(fd);
	printf("ligne 3 : %s", line);
	
	line = get_next_line(fd);
	printf("ligne 4 : %s", line);
	
	line = get_next_line(fd);
	printf("ligne 5 : %s", line);

	line = get_next_line(fd);
	printf("ligne 6 : %s", line);
	
	line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);
	line = get_next_line(fd);
	printf("ligne 7 : %s", line);
	free(line);


	
	close(fd);
}