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
#ifdef DEBUG
# include <stdio.h>
#endif
//TODO   make all man
//TODO   make the function clean_tmp
/*
**
*/

static int	error_mem(char	**buff)
{
	free(*buff);
	return (ERROR);
}

/*
**
*/

char	*return_nl(char	*tmp)
{
	char	*ret;
	size_t	len;

	len = eol_len(tmp, 1);
	if (!(ret = ft_substr(tmp, 0, len)))
		return (NULL);
	return (ret);
}

/*
**
*/

int		clean_tmp(char	**tmp)
{
	size_t	len;
	size_t	start;
	char *buff;

	start = eol_len(*tmp, 1);
	len = start - eol_len(*tmp, 3);

	if (!(buff = ft_substr(*tmp, start + 1, len)))
		return (0);
	free(*tmp);
	*tmp = buff;
	return (1);
}

/*
**   get_next_line();
**
**   Return :
**      1 =    LRD
**      0 =    EOFL
**      -1 =   Error
**
*/

int		get_next_line(int fd, char **line)
{
	static t_gnl	gnl;
	static char		*tmp;
	char		*buff;

	if (!line || BUFFER_SIZE <= 0 || fd < 0|| 
		!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERROR);
	
}
