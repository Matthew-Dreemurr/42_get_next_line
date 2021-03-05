/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/05 14:27:14 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*
**   @param `fd`      The file descriptor.
**   @param `**line`
**
**   @return L_READ (1), EO_FILE (0).
**   ERROR (-1).
**   //TODO @ EOL return a '\0' string
*/
int		get_next_line(int fd, char **line)
{
	static ssize_t	read_ret; //TODO make it static
	static char		*tmp;
	char			*buff;

	puts("\n===================================================================================================================================");
	puts("        ----------- START ----------");
	puts("            .....................    \n");
	printf("Last tmp:\n|%s|\nlast read return: %lu\n", tmp, read_ret);//TODO remove
	if (fd > FOPEN_MAX || fd < 0 || !(*line) ||
	!(buff = (char*)malloc(BUFFER_SIZE + 1)))
		return(ERROR);
	buff[BUFFER_SIZE] = '\0';
	while (!(lenStr(tmp, '\n', 2)))
	{
		if ((read_ret = read(fd, buff, BUFFER_SIZE)) == ERROR)
			return (freeRetun((void*)&buff, ERROR));
		if (read_ret < BUFFER_SIZE)
			break;
		if (!(tmp = joinStr(tmp, buff)))
		{
			free(tmp);
			return (freeRetun((void*)&buff, ERROR));
		}
		puts("\n=== while ===\n");
		printf("read ret: %lu\nread buff: \n|%s|\ntmp join: \n|%s|\n",read_ret, buff, tmp);//TODO remove
	}
	free(buff);
	if (!(*line = nextLine(&tmp)))
		return (freeRetun((void*)&tmp, ERROR));
	if (read_ret < BUFFER_SIZE)
		return (freeRetun((void*)&tmp, EO_FILE));
	return (L_READ);
}