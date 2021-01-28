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

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m"
# define B_BLK	"\x1B[30;1m"
# define B_RED	"\x1B[31;1m"
# define B_GRN	"\x1B[32;1m"
# define B_YEL	"\x1B[33;1m"
# define B_BLU	"\x1B[34;1m"
# define B_MAG	"\x1B[35;1m"
# define B_CYN	"\x1B[36;1m"
# define B_WHT	"\x1B[37;1m"
# define D_WHT	"\x1B[37;2m"
# define B_RESET	"\x1B[0m"

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
		return (ERROR);
	}
	#endif
	if (ret > 0)
	{
		#ifdef DEBUG
		printf(B_GRN "[OK] get_next_line\n\n" RESET);
		#endif
		if (!line)
			printf (RED "ERROR *line is NULL !" RESET);
		printf(B_YEL "**line" RESET " = " B_WHT "|" B_YEL "%s" B_WHT "|\n" RESET, line);
		free(line);
	}
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
	i = 1;
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
	while(i <= loop)
	{
		#ifdef DEBUG
		printf(B_YEL "\n     [..--================--..]\n" RESET);
		printf(YEL "[===========[Loop nbr %d]===========]\n" RESET, i);
		printf(B_YEL "      ['---==============---']\n" RESET);
		#endif
		ret = gnl_test(fd);
		if (ret == -1)
		{
			#ifdef DEBUG
			printf(RED "[======[ERROR]======]" RESET);
			#endif
			break;
		}
		if (ret == 0)
		{
			#ifdef DEBUG
			printf(GRN "[======[EOF]======]" RESET);
			#endif
			break;
		}
		i++;
	}
	close(fd);
	printf(GRN "\n\n[====== main EXIT =====]\n" RESET);
	return (0);
}
