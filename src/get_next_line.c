/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/15 17:55:07 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#ifdef DEBUG
# include <stdio.h>
#endif

/*
**	read_file
**	
**	read the content of the descriptor file given and written in `buff`
**	that was allocated with the BUFFER_SIZE.
**	
**	Return :
**		buff = Success
**		NULL = Error
*/

char	*read_file(int fd, t_gnl *gnl, char **buff)
{
	if (!(*buff = malloc(sizeof(char) * BUFFER_SIZE)))
		return (NULL);
	if(!(gnl->ret_read = read(fd, *buff, BUFFER_SIZE)))
		return (NULL);
	if (gnl->ret_read == -1)
		return (NULL);
	return (*buff);
}

/*
**	get_next_line
**
**	Return :
**		1 = A line has been read
**		0 = EOF
**		-1 = Error
*/

int	get_next_line(int fd, char **line)
{
	static t_gnl	gnl;
	t_gnl			*p_gnl;
	static char		*buff;

	gnl.ret_read = 0;
	p_gnl = &gnl;
	if (!(line))
		return (-1);
	
	if (!(*line = read_file(fd, p_gnl, &buff)))
	{
	//	if (buff)
	//		free(buff);
		if (gnl.ret_read == 0)
			return (0);
		return (-1);
	}
	if (gnl.ret_read == 0)
		return (0);
	//if (buff)
	//	free(buff);
	return (1); //on line was read, 0 for the EOF
}
