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
**  //TODO   do not remove the `\n` in clean_tmp();
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
	ssize_t			ret_read;
	static char		*tmp;
	char			*buff;

	if (!line || BUFFER_SIZE <= 0 || fd < 0
	|| !(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERROR);
	while (!eol_len(tmp, 1))
	{
		ft_bzero(buff, (sizeof(char) * (BUFFER_SIZE + 1)));
		if ((ret_read = read(fd, buff, BUFFER_SIZE)) == ERROR)
			return (error_mem(&buff));
		if (ret_read == 0)
		{
			free(buff);
			free(tmp);
			return (EO_FILE);
		}
		if (!(tmp = ft_strjoin(tmp, buff)))
			return (error_mem(&buff));
	}
	free(buff);
	if (!(*line = ft_substr(tmp, 0, eol_len(tmp, 2))) || !clean_tmp(&tmp))
		return (ERROR);
	return (L_READ);
}
