/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             ++  +:+       ++        */
/*                                                ++++++   ++           */
/*   Created: 2021/01/02 15:41:33 by mhadad            +    +             */
/*   Updated: 2021/01/15 15:57:08 by mhadad              .fr       */
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
	//* Call GNL *//
	ret = get_next_line(fd, &line);
	#ifdef DEBUG
	printf(B_YEL "\nGNL return" RESET " |%d|\n", ret);
	if (ret == -1)
	{
		printf(RED "/!\\ [Error_check_error]: Return fonction = -1 /!\\\n" RESET);
	}
	if (ret >= 0)
	{
		printf(B_GRN "[OK] get_next_line\n\n" RESET);
	}
	printf(B_YEL "**line" RESET " = " B_WHT "|%s|\n" RESET, line);
	#endif
	return (ret);
}

int	main()
{
	int	loop;
	int	fd;
	int	ret;
	int	i;

	loop = LOOP;
	ret = 0;
	i = 0;
		//* Check open file *//
	if((fd = open(TXT, O_RDONLY)) == -1)
	{
		#ifdef DEBUG
		printf(RED "/!\\ [Error_main]: Open " TXT " fd = |%d|/!\\\n" RESET, fd);
		#endif
		return (0);
	}
	#ifdef DEBUG
	printf(GRN "Open %s successful, File descriptor |%d|\n" RESET, TXT, fd);
	printf(YEL "Reading file |%s| whit the buffer size limit of |%d|oct\n" RESET, TXT, BUFFER_SIZE);
	#endif
	if (!(strcmp(TXT, "ERROR")))
	{
		#ifdef DEBUG
		printf(RED "/!\\ [Error_main]: Please add DEF = -D TXT=\"FILE_NAME\" to the Makefile /!\\\n" RESET);
		#endif
		return (0);
	}
	while(i < loop)
	{
		#ifdef DEBUG
		printf(B_YEL "\n     [..--====--..]\n" RESET);
		printf(YEL "[=====[Loop nbr %d]=====]\n" RESET, i);
		printf(B_YEL "    ['---=======---']\n" RESET);
		ret = gnl_test(fd);
		#endif
		if (ret == -1)
		{
			#ifdef DEBUG
			printf(RED "[======[ERROR]======]" RESET);
			#endif
			break;
		}
		else if (!ret)
		{
			#ifdef DEBUG
			printf(GRN "[======[EOF]======]" RESET);
			#endif
			break;
		}
		i++;
	}
	close(fd);
	return (0);
}
