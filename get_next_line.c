/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/08 14:01:59 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**   @param `fd`      The file descriptor.
**   @param `**line`
**
**   @return L_READ (1), EO_FILE (0).
**   ERROR (-1).
*/





//TODO
//TODO
//TODO @ EOL return a '\0' string
//TODO
//TODO
//TODO




int		get_next_line(int fd, char **line)
{
	static ssize_t	read_ret = 1;
	static char		*tmp;
	char			*buff;

#ifdef DEBUG
	puts("\n===================================================================================================================================");
	puts("        ----------- START ----------");
	puts("            .....................    \n");
	printf("fd: %d\n", fd);
	//printf("Last tmp:\n|%s|\nlast read return: %lu\n", tmp, read_ret);//TODO remove
	puts("        ----------- DEBUG ----------");
#endif
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return(ERROR);
	if (!(buff = (char*)malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	buff[BUFFER_SIZE] = '\0';
	while (!(lenStr(tmp, '\n', 2)) && (read_ret != 0))
	{
#ifdef DEBUG
		puts("\n=== while ===");
#endif
		if ((read_ret = read(fd, buff, BUFFER_SIZE)) == ERROR)
			return (freeRetun((void*)&buff, ERROR));
		buff[read_ret] = '\0';
		if (!(tmp = joinStr(tmp, buff)))
		{
			free(tmp);
			return (freeRetun((void*)&buff, ERROR));
		}
#ifdef DEBUG
		printf("read ret: %lu\nread buff: \n|%s|\ntmp join: \n|%s|\n",read_ret, buff, tmp);//TODO remove
#endif
	}
	free(buff);
	if (read_ret == 0 && !lenStr(tmp, '\n', 2))
	{
		*line = joinStr(NULL, NULL);
		//puts(RESET "\nreturn EOF\n\n");
		return (/*freeRetun((void*)&tmp, */EO_FILE/*)*/);
	}
		//printf("tmp: \n|%s|\n",tmp);//TODO remove
	if (!(*line = nextLine(&tmp)))
		return (freeRetun((void*)&tmp, ERROR));
	//puts(RESET "\n\nreturn L_READ\n");
	return (L_READ);
}