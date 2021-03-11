#if 0
// #include "get_next_line.h"
// #include <stdio.h>
// #include <fcntl.h>
// #include <sys/uio.h>
// #include <sys/types.h>

// # define NUM_FD 3

// int	main(int argc, char const *argv[])
// {
// 	int		ret[NUM_FD];
// 	int		fd[NUM_FD];
// 	char	*line[NUM_FD];

// 	ssize_t	i;

// 	if (argc != NUM_FD + 1)
// 		return (1);
// 	i = 0;
// 	while (i < NUM_FD)
// 	{
// 		fd[i] = open(argv[i + ], O_RDONLY);
// 		if (fd[i] < 0)
// 			fd[i] = 0;
// 		i++;
// 	}
// 	while (1)
// 	{
// 		i = 0;
// 		while (i < NUM_FD)
// 		{
// 			ret[i] = get_next_line(fd[i], &line[i]);
// 			printf("[i %ld][fd %d]ret %d | '%s'\n", i, fd[i], ret[i], line[i]);
// 			free(line[i]);
// 			line[i] = NULL;
// 			i++;
// 		}
// 		i = 0;
// 		while (i < NUM_FD && ret[i] == 0)
// 			i++;
// 		if (i == NUM_FD - 1)
// 			break ;
// 	}
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-multiple-fds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:05:34 by jaleman           #+#    #+#             */
/*   Updated: 2016/12/09 16:07:23 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>

int	main(int argc, char const *argv[]) {
	int fd;
	int fd_2;
	int i;
	char *line;
	int status;

	fd = open(argv[1], O_RDONLY);
	i = 1;
	while ((status = get_next_line(fd, &line)) == 1 && i < 500)
	{
		printf("[%d] %s\n", i++, line);
		free(line);
	}
	fd_2 = open(argv[2], O_RDONLY);
	close(fd);
	fd = fd_2;
	while ((status = get_next_line(fd, &line)) == 1)
	{
		printf("[%d] %s\n", i++, line);
		free(line);
	}
	return (argc);
}
#endif

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

#define DISPLAY(ret, fd)                                             \
	printf(">> R %d fd %d | Line \"%s\"\n", ret, fd, line);

int main(int argc, char*argv[])
{
	char *line;
	int fd[FOPEN_MAX];
	int ret[FOPEN_MAX];

	fd[0] = 0;
	ret[0] = 0;
	line = NULL;
	if (argc == 2)
	{
		if ((fd[0] = open(argv[1], O_RDONLY))== -1)
			return (1);
		while ((ret[0] = get_next_line(fd[0], &line)) > 0)
		{
			DISPLAY(ret[0], fd[0]);
			free(line);
		}
		DISPLAY(ret[0], fd[0]);
		free(line);
	}
	if (argc == 3)
	{
		if ((fd[0] = open(argv[1], O_RDONLY)) == -1)
			return (1);
		if ((fd[1] = open(argv[2], O_RDONLY)) == -1)
			return (1);
		ret[0] = 1;
		ret[1] = 1;

		while (ret[0] > 0 && ret[1] > 0)
		{
			if ((ret[0] = get_next_line(fd[0], &line)) >= 0)
			{
				DISPLAY(ret[0], fd[0]);
				free(line);
				line = NULL;
			}
			if ((ret[1] = get_next_line(fd[1], &line)) >= 0)
			{
				DISPLAY(ret[1], fd[1]);
				free(line);
				line = NULL;
			}
		}
		free(line);
		close(fd[0]);
		close(fd[1]);
	}
	else if (argc > 3)
	{
		int i = 1;

		while (i < argc)
		{
			fd[i] = open(argv[i], O_RDONLY);
			printf("argc %d | %i", argc, i);
			while ((ret[i] = get_next_line(fd[i], &line) > 0))
			{
				DISPLAY(ret[i], fd[i]);
				free(line);
				line = NULL;
			}
			DISPLAY(ret[i], fd[i]);
			free(line);
			line = NULL;
			close(fd[i]);
			i++;
		}
	}
	return (0);
}