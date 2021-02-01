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
**   clean_tmp();
**
** DESCRIPTION
**   Will remove all charater precede the first '\n' find and.
**
** PARAMETERS
**   @param `tmp`   Pointer to a string.
**
** RETURN
**   1 if successful.
**   0 if failed.
*/

int			clean_tmp(char **tmp)
{
	size_t	len;
	size_t	start;
	char	*buff;

	start = eol_len(*tmp, 2);
	len = eol_len(*tmp, 3) - start;
	if (!(buff = ft_substr(*tmp, start + 1, len)))
		return (0);
	free(*tmp);
	*tmp = buff;
	return (1);
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
	
}
