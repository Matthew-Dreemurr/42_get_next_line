/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:41:33 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/15 15:43:12 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>

#ifndef TXT
# define TXT "ERROR"
#endif
#ifndef LOOP
# define LOOP 1
#endif

int	gnl_test(int fd)
{
	char		*line;
	int			ret;

	ret = 0;
	printf("#Reading file |%s| whit the buffer size limit of |%d|oct\n", TXT, BUFFER_SIZE);
	if (!(strcmp(TXT, "ERROR")))
	{
		printf("##/!\\ [{Error}_main]: Please add DEF = -D TXT=\"FILE_NAME\" to the Makefile /!\\\n");
		return (0);
	}
#ifdef TXT
	//* Call GNL *//

	printf("\n[===[GNL: start]===]\n");
	ret = get_next_line(fd, &line);
	printf("GNL return |%d|\n", ret);
	if (ret == -1)
	{
		printf("###/!\\ [{Error}_check_error]: Return fonction = -1 /!\\\n");
	}
	if (ret == 0)
	{
		printf("###[{OK}_get_next_line]\n\n\n");
	}
	printf("##line read = |%s|\n", line);
	printf("[===[GNL: stop]===]\n");
	printf("\n[=========================================]\n\n\n");
	free(line);
	return (ret);
}

int	main()
{
	int	loop;
	int	fd;
	int	ret;

	loop = LOOP;
	ret = 0;
		//* Check open file *//
	if((fd = open(TXT, O_RDONLY)) == -1)
	{
		printf("##/!\\ [{Error}_main]: Open " TXT " fd = |%d|/!\\\n", fd);
		return (0);
	}
	printf("##Open %s successful, File descriptor |%d|\n", TXT, fd);
	while(loop--)
	{
		ret = gnl_test(fd);
		if (ret == -1)
		{
			printf("[======[ERROR]======]");
			break;
		}
		else if (!ret)
		{
			printf("[======[EOF]======]");
			break;
		}
	}
	return (0);
}
#endif