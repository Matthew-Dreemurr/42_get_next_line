/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/25 16:22:34 by mhadad           ###   ########.fr       */
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
#ifdef DEBUG
printf(B_RED "\nerror_mem ERROR EXIT" RESET);
#endif
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

char	*clean_tmp(char	tmp)
{
	
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

int		get_next_line(int fd, char **line)
{
	static t_gnl	gnl;
	static char		*tmp;
	char		*buff;

	if (!line || !(BUFFER_SIZE > 0) )
		return (ERROR);
#ifdef DEBUG
printf(B_YEL "\nThe last tmp" B_WHT " = |%s|\n" RESET, tmp);
#endif
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERROR);
	ft_bzero(buff, BUFFER_SIZE + 1);
	while (!eol_len(tmp, 0))
	{
		if ((gnl.ret_read = read(fd, buff, BUFFER_SIZE)) == -1)
			return(error_mem(&buff));
		buff[gnl.ret_read] = '\0';
#ifdef DEBUG
printf(YEL "\n\n╔ ..====.. while ..====.." RESET);
//printf(B_YEL "\n╠ ╔ gnl.len = " RESET "[%lu]\n", gnl.len);
printf(B_YEL "╠ ╠ gnl.ret_read = " RESET "[%lu]\n", gnl.ret_read);
printf(B_YEL "╠ ╠ Read & last = \'\\0\'" B_GRN "[Ok]\n" RESET "╠");
printf(B_YEL " ╠\n╠ ╚ Read buff" B_WHT " = |%s|\n╠" RESET, buff);
#endif
		if (!(tmp = ft_strjoin(tmp, buff)))
			return (error_mem(&buff));
	}
#ifdef DEBUG
printf(YEL "\n╚ ''===='' while ''===='' " B_GRN "[Ok]\n" RESET);
#endif
	if (!(*line = return_nl(tmp)))
		return(error_mem(&buff));
	free(buff);
	if (!gnl.ret_read)
		return (EOF);
	return (LRD);
}
