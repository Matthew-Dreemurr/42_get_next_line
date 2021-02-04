/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/25 16:45:26 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*
**  //TODO   make all man
*/

/*
**   error_mem();
**
** DESCRIPTION
**   Free the adresse pointed by `buff` and returns the `ERROR` value.
**
** PARAMETERS
**   @param `buff`   Pointer of pointer.
**
** RETURN
**   The `ERROR` value.
*/

static int	error_mem(char **buff)
{
	free(*buff);
	return (ERROR);
}

/*
**   lstcheck_fd();
**
** DESCRIPTION
**
**
**
**
** PARAMETERS
**
**
**
** RETURN
**
*/

void	*lstcheck_fd(t_gnl list)
{

}

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
**   A line has been read   L_READ
**   End of line            EO_FILE
**   Error                  ERROR
*/

int			get_next_line(int fd, char **line)
{
	static t_gnl	list;
	t_gnl			*list_fd;
	char			*buff;

	list_fd = lstcheck_fd(list);
	if (!(buff = malloc(BUFFER_SIZE + 1)))
		return (ERROR);

	free(buff);
	return (L_READ);
}
