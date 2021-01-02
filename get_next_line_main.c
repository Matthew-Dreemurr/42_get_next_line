/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:41:33 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/02 16:01:14 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	check_error(int fd, char **line )
{

	if (-1 == (get_next_line(fd, line)))
	{
		printf("/!\\ [CRASH] /!\\");
	}

	return (1);
}

int	main()
{
	int		fd;
	char	**line;

	fd = 1;
	check_error(fd, line);
	return (0);
}