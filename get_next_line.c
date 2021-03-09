/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/09 11:33:32 by mhadad           ###   ########.fr       */
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
	while (lenStr(box.buff, '\n', 2) && !(box.readRet < BUFFER_SIZE))
	{
		if ((box.readRet = read(fd, box.buff, BUFFER_SIZE)) < 0)
			return (ERROR);
		if (!(box.tmp[fd] = joinStr(box.tmp[fd], box.buff, FALSE, FALSE)))
			return (ERROR);
	}
	free(box.buff);
	if (!(*line = nextLine(&(box).tmp[fd])))
		return (freeRetun(&(box).tmp[fd], ERROR));
	if (box.readRet)
		return (L_READ);
	else if (!box.readRet)
		return (freeRetun(&(box).tmp[fd], EO_FILE));
}