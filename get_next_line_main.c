/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:05:34 by jaleman           #+#    #+#             */
/*   Updated: 2021/03/10 17:09:57 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>

int	main(int argc, char const *argv[]) {
	int fd;
	int fd_2;
	int i;
	char *line;
	int status;

		printf(B_YEL "\n     [..--================--..]\n" RESET);
		printf(YEL "[===========[START]===========]\n" RESET, i);
		printf(B_YEL "      ['---==============---']\n" RESET);
	fd = open(argv[1], O_RDONLY);
	i = 1;
	while ((status = get_next_line(fd, &line)) == 1 && i < 500)
	{
		printf(B_YEL "\n  [..--================--..]\n" RESET);
		printf(YEL "[===========[return %d]===========]\n" RESET, status);
		printf("[%d] ", i++);
		PRINT_DETAILS(line);
		printf("\n");
		free(line);
		printf(B_YEL "\n     [..--================--..]\n" RESET);
		printf(YEL "[===========[Loop nbr %d]===========]\n" RESET, i);
		printf(B_YEL "      ['---==============---']\n" RESET);
	}
	printf(B_YEL "\n  [..--================--..]\n" RESET);
	printf(YEL "[===========[return %d]===========]\n" RESET, status);
	PRINT_DETAILS(line);
	fd_2 = open(argv[2], O_RDONLY);
	free(line);
	close(fd);
	fd = fd_2;
	i = 1;
	while ((status = get_next_line(fd, &line)) == 1)
	{
		printf(B_YEL "\n  [..--================--..]\n" RESET);
		printf(YEL "[===========[return %d]===========]\n" RESET, status);
		printf("[%d] ", i++);
		PRINT_DETAILS(line);
		printf("\n");
		free(line);
		printf(B_YEL "\n     [..--================--..]\n" RESET);
		printf(YEL "[===========[Loop nbr %d]===========]\n" RESET, i);
		printf(B_YEL "      ['---==============---']\n" RESET);
	}
	printf(B_YEL "\n  [..--================--..]\n" RESET);
	printf(YEL "[===========[return %d]===========]\n" RESET, status);
	PRINT_DETAILS(line);
	return (argc);
}


//	while (1)
//	{
//		ret = get_next_line(fd, &line);
//		printf("ret %d | '%s'\n", ret, line);
//		free(line);
//		if (ret <= 0)
//			break ;
//	}