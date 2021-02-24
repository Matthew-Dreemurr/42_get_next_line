/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/02/24 21:29:27 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*
**   @param `fd`      The file descriptor.
**   @param `**line`
**
**   @return L_READ (1), EO_FILE (0).
**   ERROR (-1).
*/
int		get_next_line(int fd, char **line)
{
	static t_box	box;
	static char		*tmp[FOPEN_MAX];

	if (fd < 0 || fd > FOPEN_MAX || !line ||
	!(box.buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	box.buff[BUFFER_SIZE] = '\0';
	while ((diyStrLen(tmp[fd], '\n', 2) <= 0))
	{
		if ((box.readR = read(fd, box.buff, BUFFER_SIZE)) == ERROR)
			return (retFree(&box.buff, ERROR));
		box.buff[box.readR] = '\0';
		if ((joinStr(&tmp[fd], box.buff)) < 0)
			retFree(&box.buff, ERROR);
#ifdef DEBUG
	printf("Read ret: |%lu|, Read buff: |%s|\n", box.readR, box.buff);
	printf("strjoin tmp[%d]: |%s|\n\n", fd, tmp[fd]);
#endif
	}
	if (!(*line = tmpClean(&tmp[fd])))
		return (ERROR);
	free (box.buff);
	if (box.readR < BUFFER_SIZE)
		return(retFree(&tmp[fd], EO_FILE));
	return (L_READ);
}