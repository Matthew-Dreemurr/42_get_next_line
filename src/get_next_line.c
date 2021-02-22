/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/02/22 16:48:36 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*
**   get_next_line();
**
** DESCRIPTION
**
**
** PARAMETERS
**
**
** RETURN
**   A line has been read   L_READ  = 1
**   End of line            EO_FILE = 0
**   Error                  ERROR   = -1
*/

int		get_next_line(int fd, char **line)
{
	static t_box	box;
	const char		*tmp[FOPEN_MAX];
	char			*buff;

	if (fd < 0 || fd > FOPEN_MAX || !line ||
	!(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	while (!diy_strlen(buff, '\n', 2))
	{
		if (ERROR == (box.read_ret = read(fd, buff, BUFFER_SIZE)))
			return (ret_free(&buff, ERROR));
	
	}
	if (box.read_ret < BUFFER_SIZE)
		return(EO_FILE);
	return (EO_FILE);
}