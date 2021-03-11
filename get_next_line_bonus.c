/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:21:39 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/11 15:26:19 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**   @param  `fd`      The file descriptor.
**   @param  `**line`
**   @param  `box`:
**     `*tmp`         .
**     `*buff`        .
**     `ret`      .
**
**   @return L_READ (1), EO_FILE (0).
**   ERROR (-1).
*/

int		get_next_line(int fd, char **line)
{
	static t_box	box[FOPEN_MAX];

	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd >= FOPEN_MAX ||
	!(box[fd].buff = (char*)malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	box[fd].ret = 1;
	box[fd].buff[0] = '\0';
	while (!(lentochar(box[fd].buff, '\n', 2)) && box[fd].ret)
	{
		if ((box[fd].ret = read(fd, box[fd].buff, BUFFER_SIZE)) ==
		(ssize_t)ERROR)
			return (free_return((void*)&box[fd].buff, ERROR));
		box[fd].buff[box[fd].ret] = '\0';
		if (!(box[fd].tmp = join_str(box[fd].tmp, box[fd].buff, &box[fd].tmp)))
			return (free_return((void*)&box[fd].buff, ERROR));
	}
	free(box[fd].buff);
	if (!(lentochar(box[fd].tmp, '\n', 2)))
	{
		*line = join_str(box[fd].tmp, NULL, &box[fd].tmp);
		return (EO_FILE);
	}
	if (!(*line = next_line(&box[fd].tmp)))
		return (ERROR);
	return (L_READ);
}
