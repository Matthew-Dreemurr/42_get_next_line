/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/02/16 21:36:10 by mhadad           ###   ########.fr       */
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

int		error_mem(char **buff)
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

t_gnl	*lstcheck_fd(t_gnl **list, int fd)
{
	t_gnl	*tmp;

	if (!*list)
		return (NULL);
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
	if (!(lst = lstcheck_fd(list, fd)))
		return (error_mem(&buff));
	
	while (!eol_len(lst->tmp, 1))
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		if ((lst->read_ret = read(lst->fd, buff, BUFFER_SIZE)) == ERROR)
		{
			//free_lst_fd();
			return (error_mem(&buff));
		}
		if (!(lst->tmp = ft_strjoin(lst->tmp, buff)))
			return (error_mem(&buff));
	}
	free(buff);
	if (!(*line = ft_substr(lst->tmp, 0, eol_len(lst->tmp, 2)))
	|| !(clean_tmp(&(lst->tmp))))
	{
		//free_lst_fd();
		return (error_mem(&buff));
	}

	if (lst->read_ret =! BUFFER_SIZE)
		return (EO_FILE);
	return (L_READ);
}

//TODO free list when EOF reatch and move the list->next