/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:41:33 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/02 19:49:35 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>

int	check_error(int fd, char **line)
{

	if (-1 == (get_next_line(fd, line)))
	{
		printf("/!\\ [{Error}_check_error]: Return fonction = -1 /!\\\n");
	}
	else
	{
		printf("[{OK}_check_error]\n");
	}
	
	return (1);
}

int	main()
{
	int			fd;
	static char	**line;


	printf("TXT = |%s|, BUFFER_SIZE = |%d|\n", TXT, BUFFER_SIZE);
	if ((char *)TXT == (char *)"NOPE")
	{
		printf("/!\\ [{Error}_main]: Please add DEF = -D TXT=\"FILE_NAME\" to the Makefile /!\\\n");
		return (1);
	}
	if((fd = open(TXT, O_RDONLY)) == -1)
	{
		printf("/!\\ [{Error}_main]: Open " TXT " fd = |%d|/!\\\n", fd);
		return (1);
	}
	printf("Open successful, File descriptor |%d|\n", fd);
	check_error(fd, line);
	free(line);
	return (0);
}