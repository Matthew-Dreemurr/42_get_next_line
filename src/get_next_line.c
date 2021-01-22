/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/22 15:00:46 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#ifdef DEBUG
# include <stdio.h>
#endif

/*
**
*/

int	free_mem(char **buff)
{
	free(*buff);
	return (ERROR);
}

/*
**   get_next_line();
**
**   Return :
**      1 =    LRD
**      0 =    EOF
**      -1 =   Error
**
**   typedef struct	s_gnl
**   {
**   	size_t		index;
**   	size_t		len;
**   	ssize_t		ret_read;
**   }				t_gnl;
*/

int	get_next_line(int fd, char **line)
{
	static t_gnl	gnl;
	static char		*buff;
	static char		*tmp;

	tmp = NULL;
	if (!line)
		return (ERROR);
#ifdef DEBUG
printf(B_YEL "\nThe last buff" RESET " = |%s|\n", buff);
#endif
	if (!(buff = malloc(sizeof(buff) * BUFFER_SIZE + 1)))
		return (ERROR);
	buff[BUFFER_SIZE] = '\0';
#ifdef DEBUG
printf(B_YEL "\nAlloc & last = \'\\0\' " B_GRN "[Ok]\n" RESET);
#endif
	while (!(gnl.len = eol_len(tmp, 0)))
	{
#ifdef DEBUG
	printf(B_YEL "gnl.len = " B_WHT "[%lu]\n" RESET, gnl.len);
#endif
		if ((gnl.ret_read = read(fd, &buff, BUFFER_SIZE) == -1))
			return(free_mem(&buff));
		buff[gnl.ret_read] = '\0';
#ifdef DEBUG
	printf(B_YEL "\nRead & last = \'\\0\'" B_GRN "[Ok]\n" RESET);
#endif
#ifdef DEBUG
printf(B_YEL "\nRead buff" RESET " = |%s|\n", buff);
#endif
		if (!(tmp = ft_strjoin(tmp, buff)))
			return (free_mem(&buff));
	}
#ifdef DEBUG
printf(B_YEL "\nWhile break " B_GRN "[Ok]\n" RESET);
#endif
	*line = buff;
	if (!gnl.ret_read)
		return (EOF);
	return (LRD);
}
