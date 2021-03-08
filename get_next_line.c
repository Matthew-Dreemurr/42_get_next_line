/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/08 15:53:03 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**   @param `fd`      The file descriptor.
**   @param `**line`
**
**   @return L_READ (1), EO_FILE (0).
**   ERROR (-1).
*/

int		get_next_line(int fd, char **line)
{
	static ssize_t	read_ret = 1;
	static char		*tmp;
	char			*buff;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return(ERROR);
	if (read_ret == 0 && !lenStr(tmp, '\n', 2))
	{
		*line = joinStr(NULL, NULL);
		return (freeRetun((void*)&tmp, EO_FILE));
	}
	if (!(buff = (char*)malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	buff[BUFFER_SIZE] = '\0';
	while (!(lenStr(tmp, '\n', 2)) && (read_ret != 0))
	{
		if ((read_ret = read(fd, buff, BUFFER_SIZE)) == ERROR)
			return (freeRetun((void*)&buff, ERROR));
		buff[read_ret] = '\0';
		if (!(tmp = joinStr(tmp, buff)))
		{
			free(tmp);
			return (freeRetun((void*)&buff, ERROR));
		}
	}
	free(buff);
	if (!(*line = nextLine(&tmp)))
		return (freeRetun((void*)&tmp, ERROR));
	return (L_READ);
}