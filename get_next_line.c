/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/09 14:53:51 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**   @param  `fd`      The file descriptor.
**   @param  `**line`
**   @param  `box`:
**     `*tmp`         .
**     `*buff`        .
**     `readRet`      .
**
**   @return L_READ (1), EO_FILE (0).
**   ERROR (-1).
*/
int		get_next_line(int fd, char **line)
{
	static t_box	box;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd > FOPEN_MAX)
		return (ERROR);
	if (!(box.buff = (char*)malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	box.buff[BUFFER_SIZE] = '\0';
	box.readRet = BUFFER_SIZE;
	while (!(lenStr(box.buff, '\n', 2)) && !(box.readRet < BUFFER_SIZE))
	{
		//printf("=== while ===");
		if ((box.readRet = read(fd, box.buff, BUFFER_SIZE)) < 0)
			return (ERROR);
		box.buff[box.readRet] = '\0';
		if (!(box.tmp[fd] = joinStr(box.tmp[fd], box.buff, TRUE, FALSE)))
			return (ERROR);
	}
	free(box.buff);
	//printf("tmp @ end: |%s|\n", box.tmp[fd]);
	if (box.readRet < BUFFER_SIZE && !(lenStr(box.tmp[fd], '\n', 2)))
	{
		*line = joinStr(box.tmp[fd], NULL, FALSE, FALSE);
		return (freeRetun((void*)&(box).tmp[fd], EO_FILE));
	}
	if (!(*line = nextLine(&(box).tmp[fd])))
		return (freeRetun((void*)&(box).tmp[fd], ERROR));
	return (L_READ);
}