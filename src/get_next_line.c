/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/02 17:27:59 by mhadad           ###   ########.fr       */
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
#ifdef DEBUG
	printf("\n\n==last tmp: |%s|\n", tmp[fd]);
#endif
	while (!(diyStrLen(tmp[fd], '\n', 3)))
	{
#ifdef DEBUG
	printf(RED "\n\n==WHILE\n" RESET);
#endif
		if ((box.readR = read(fd, box.buff, BUFFER_SIZE)) == ERROR)
			return (retFree(&box.buff, ERROR));
		box.buff[box.readR] = '\0';
		if (!(tmp[fd] = joinStr(tmp[fd], box.buff)))
			retFree(&box.buff, ERROR);
#ifdef DEBUG
	printf("\n\n==last tmp: |%s|\n", tmp[fd]);
	printf("\n\n==Read ret: |%lu|, Read buff: \n|%s|\n", box.readR, box.buff);
#endif
	}
	if (!(*line = retNextLine(tmp[fd])))
		return (ERROR);
	if (!(tmp[fd] = tmpClean(tmp[fd])))
		return (ERROR);
	free (box.buff);
	if (box.readR < BUFFER_SIZE)
		return(retFree(&tmp[fd], EO_FILE));
	return (L_READ);
}