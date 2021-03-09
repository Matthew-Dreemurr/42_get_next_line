/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:42 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/09 11:46:34 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
#include "wraloc.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	128
# endif




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




/*
**   Return macro.
**
**   A line has been read   L_READ
**   End of line            EO_FILE
**   Error                  ERROR
*/

# define L_READ			1
# define EO_FILE		0
# define ERROR			-1

/*
**   Bool macro.
*/

# define TRUE			1
# define FALSE			0

/*
**   Struct
*/

typedef struct	s_box
{
	char	*tmp[FOPEN_MAX];
	char	*buff;
	size_t	readRet;
}				t_box;


/*
**   All fonction prototype
*/

int		get_next_line(int fd, char **line);
int		freeRetun(void **addr, int ret);
ssize_t	lenStr(const char *str, int c, int mode);
char	*joinStr(char *s1, char *s2, int freeS1, int freeS2);
char	*nextLine(char	**str);
#endif
