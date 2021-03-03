/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/03 15:43:40 by mhadad           ###   ########.fr       */
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
	ssize_t		read_ret;
	static char	*tmp[FOPEN_MAX];
	char		*buff;

	puts("GNL START");
	if (fd > FOPEN_MAX || fd < 0 || !(*line) ||
	!(buff = (char*)malloc(BUFFER_SIZE + 1)))
		return(ERROR);
	buff[BUFFER_SIZE] = '\0';
	while (!(lenStr(tmp[fd], '\n')))
	{
		if ((read_ret = read(fd, buff, BUFFER_SIZE)) == ERROR)
			return (freeRetun((void*)&buff, ERROR));
		if (!(tmp[fd] = joinStr(tmp[fd], buff)))
			return (freeRetun((void*)&buff, ERROR));
	}
	free(buff);
	*line = tmp[fd];
	if (read_ret < BUFFER_SIZE)
		return (freeRetun((void*)&tmp[fd], EO_FILE));
	return (L_READ);
}