/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/09 10:53:56 by mhadad           ###   ########.fr       */
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
	while (lenStr(box.buff, '\n', 2))
	{
		if ((box.readRet = read(fd, box.buff, BUFFER_SIZE)) < 0)
			return (ERROR);
		
	}
	
}