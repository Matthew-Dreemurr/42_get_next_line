/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/02/22 23:28:47 by mhadad           ###   ########.fr       */
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
	while (!diy_strlen(buff, '\n', 2))
	{
		if (ERROR == (box.read_ret = read(fd, buff, BUFFER_SIZE)))
			return (ret_free(&buff, ERROR));
		buff[box.read_ret] = '\0';
		
		joinstr(tmp[fd], tmp[fd], buff);//TODO
#ifdef DEBUG
	printf("Read ret: |%lu|, Read buff: |%s|\n", box.read_ret, buff);
#endif
	}
	free (buff);
	if (box.read_ret < BUFFER_SIZE)
		return(EO_FILE);
	return (EO_FILE);
}