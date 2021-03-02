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
# define TXT2 "ERROR"
#endif
#ifndef LOOP
# define LOOP 1
#endif

#ifdef TEST1
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
	int	fd2;
	int	ret;
	int	i;
	int	j;

	loop = LOOP;
	ret = 0;
	i = 1;
	j = i;
		//* Check open file *//
	if((fd = open(TXT, O_RDONLY)) == -1)
	{
		#ifdef DEBUG
		printf(RED "/!\\ [Error_main]: Open " TXT " fd = |%d|/!\\\n" RESET, fd);
		#endif
		return (0);
	}
	if((fd2 = open(TXT2, O_RDONLY)) == -1)
	{
		#ifdef DEBUG
		printf(RED "/!\\ [Error_main]: Open " TXT2 " fd = |%d|/!\\\n" RESET, fd);
		#endif
		return (0);
	}
	#ifdef DEBUG
	printf(GRN "Open %s successful, File descriptor |%d|\n" RESET, TXT, fd);
	printf(YEL "Reading file |%s| whit the buffer size limit of |%d|oct\n" RESET, TXT, BUFFER_SIZE);
	printf(GRN "Open %s successful, File descriptor |%d|\n" RESET, TXT2, fd2);
	printf(YEL "Reading file |%s| whit the buffer size limit of |%d|oct\n" RESET, TXT2, BUFFER_SIZE);
	#endif
	if (!(strcmp(TXT, "ERROR")))
	{
		#ifdef DEBUG
		printf(RED "/!\\ [Error_main]: Please add DEF = -D TXT=\"FILE_NAME\" to the Makefile /!\\\n" RESET);
		#endif
		return (0);
	}
	if (!(strcmp(TXT2, "ERROR")))
	{
		#ifdef DEBUG
		printf(RED "/!\\ [Error_main]: Please add DEF = -D TXT2=\"FILE_NAME\" to the Makefile /!\\\n" RESET);
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
	while(j <= loop)
	{
		#ifdef DEBUG
		printf(B_YEL "\n     [..--================--..]\n" RESET);
		printf(YEL "[===========[Loop nbr %d]===========]\n" RESET, j);
		printf(B_YEL "      ['---==============---']\n" RESET);
		#endif
		ret = gnl_test(fd2);
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
			printf(GRN "  [..======[EOF]======..]\n" RESET);
			printf(GRN "[==========[EOF]==========]\n" RESET);
			printf(GRN "  [''======[EOF]======'']\n" RESET);
			#endif
			break;
		}
		j++;
	}
	close(fd);
	close(fd2);
	printf(GRN "\n\n[====== main EXIT =====]\n" RESET);
	return (0);
}
#endif

#ifdef TEST2
int main()
{
        int             fd;
        int             i;
        int             j;
        char                    *line = 0;
        char                    *lineadress[1056];

        j = 1;
        printf("\n==========================================\n");
        printf("========== TEST 1 : The Alphabet =========\n");
        printf("==========================================\n\n");

        if (!(fd = open("test/lorem_ipsum_of_the_doom.UwU", O_RDONLY)))
        {
                printf("\nError in open\n");
                return (0);
        }
        while ((i = get_next_line(fd, &line)) > 0)
        {
                printf(YEL "|%s|\n" RESET, line);
                lineadress[j - 1] = line;
                j++;
        }
        printf(YEL "|%s|\n" RESET, line);
        free(line);
        close(fd);

                if (i == -1)
                printf ("\nError in Fonction - Returned -1\n");
        else if (j == 66)
                printf("\nRight number of lines\n");
        else if (j != 66)
                printf("\nNot Good - Wrong Number Of Lines\n");
        while (--j > 0)
                free(lineadress[j - 1]);
}

#endif