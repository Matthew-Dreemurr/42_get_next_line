/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:41:33 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/02 16:10:49 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

	fd = 1;
	if (!(line = malloc(sizeof(char) * 3)))
	{
		printf("[{Error}_main]: Malloc");
		return (1);
	}
	check_error(fd, line);
	free(line);
	return (0);
}