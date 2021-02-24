/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:42 by mhadad            #+#    #+#             */
/*   Updated: 2021/02/24 20:23:27 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	128
# endif

/*
**   A line has been read   L_READ
**   End of line            EO_FILE
**   Error                  ERROR
*/

# define L_READ			1
# define EO_FILE		0
# define ERROR			-1

/*
**   Struct
*/

typedef struct	s_box
{
	ssize_t	readR;
	char	*buff;
}				t_box;


/*
**   All fonction prototype
*/

int		get_next_line(int fd, char **line);
ssize_t	diyStrLen(char *str, char c, int mode);
int		retFree(char **addr, int ret);
int		joinStr(char **dest, char *s1);
char	*tmpClean(char **tmp);

#endif
