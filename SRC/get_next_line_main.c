/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:41:33 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/02 18:24:42 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	check_error(int fd, char **line )
{

	if (-1 == (get_next_line(fd, line)))
	{
		printf("/!\\ [{Error}_check_error]: Return fonction /!\\\n");
	}
	else
	{
		printf("[{OK}_check_error]\n");
	}
	
	return (1);
}

int	main()
{
	int		fd;
	char	**line;

	printf("|%d| test\n", BUFFER_SIZE);
	if (TXT == "NOPE")
	{
		printf("/!\\ [{Error}_main]: Please add DEF = -D TXT=\"FILE_NAME\" to the Makefile /!\\\n");
		return (1);
	}
	if(!(fd = open(TXT, 'r')))
	{
		printf("/!\\ [{Error}_main]: Open " TXT "/!\\\n");
		return (1);
	}
	check_error(fd, line);
	free(line);
	return (0);
}