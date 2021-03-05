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
#include<time.h>

#ifndef TXT
# define TXT "ERROR"
# define TXT2 "ERROR"
#endif
#ifndef LOOP
# define LOOP 1
#endif

int		main()
{
	time_t t;   // not a primitive datatype
    time(&t);
	char	*line;
	int		ret;
	int		fd;

	printf("%s", ctime(&t));
	fd = open(TXT, O_RDONLY);
//	puts("Open\n");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("\nGnl ret: %d\n", ret);
		printf(YEL "Line: |%s|\n" RESET, line);
		free(line);
	}
		printf("\nEOF Gnl ret:\n|%d|\n", ret);
		printf(YEL "\nLine: |%s|\n" RESET, line);
		free(line);
		close(fd);
	return (0);
}