/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:35:25 by maissam           #+#    #+#             */
/*   Updated: 2025/11/14 15:06:45 by maissam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(stash, '\n') && read_bytes > 0)
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), free(stash), NULL);
		if (read_bytes == 0)
		{
			free(buffer);
			if (stash && *stash == '\0')
				return (free(stash), NULL);
			return (stash);
		}
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (free(buffer), stash);
}

char	*get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_substr(stash, 0, i +(stash[i] == '\n'));
	return (line);
}

char	*next_line(char *stash)
{
	char	*leftover;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	leftover = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
	return (free(stash), leftover);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = next_line(stash);
	return (line);
}
// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	char *l;
// 	int i;
// 	i = 0;
// 	int	fd;
// 	fd = open("test.txt", O_RDWR);
// 	while(fd > 0)
// {
// 	l = get_next_line(fd);
// 	printf("LINE %d : %s",i,l);
// 	i++;
// 	if(!l)
// 		break;
// 	free(l);
// }
// return (0);
// }
