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

void	*lstcheck_fd(t_gnl **list, int fd)
{
	t_gnl	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp->next = malloc(sizeof(t_gnl))))
		return (NULL);
	tmp = tmp->next;
	tmp->fd = fd;
	return (tmp);
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
//TODO check if read return is < BUFFER_S
int			get_next_line(int fd, char **line)
{
	static t_gnl	list;
	t_gnl			*lst;
	char			*buff;

	if (!(buff = malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	buff[BUFFER_SIZE] = '\0';
	if (!(lst = lstcheck_fd(&list, fd)))
		return (error_mem(&buff));
	
	while (!eol_len(lst->tmp, 1))
	{
		if ((lst->read_ret = read(lst->fd, buff, BUFFER_SIZE)) == ERROR)
		{
			free()
		}

	}
	if (eol_len(buff, 3) != BUFFER_SIZE)
	free(buff);
	return (L_READ);
}

//TODO free list when EOF reatch