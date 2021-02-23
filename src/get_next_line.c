/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/02/23 16:09:13 by mhadad           ###   ########.fr       */
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
	char			*buff;

	(void)tmp;//TODO
	
	if (fd < 0 || fd > FOPEN_MAX || !line ||
	!(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	buff[BUFFER_SIZE] = '\0';
	while ((diyStrlen(tmp[fd], '\n', 2) <= 0))
	{
		if (ERROR == (box.read_ret = read(fd, buff, BUFFER_SIZE)))
			return (retFree(&buff, ERROR));
		buff[box.read_ret] = '\0';
		if ((joinstr(&tmp[fd], buff)) < 0)
			retFree(&buff, ERROR);
#ifdef DEBUG
	printf("Read ret: |%lu|, Read buff: |%s|\n", box.read_ret, buff);
	printf("strjoin tmp[%d]: |%s|\n\n", fd, tmp[fd]);
#endif
	}
	free (buff);
	*line = tmp[fd];
	if (box.read_ret < BUFFER_SIZE)
		return(retFree(&tmp[fd], EO_FILE));
	return (L_READ);
}