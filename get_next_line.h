/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:52:10 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/11 16:54:03 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

/*
**   Return macro.
**
**   A line has been read   L_READ
**   End of line            EO_FILE
**   Error                  ERROR
*/

# define L_READ		1
# define EO_FILE	0
# define ERROR		-1

/*
**   Bool macro.
*/

# define TRUE		1
# define FALSE		0

/*
**   Struct
*/

typedef struct	s_box
{
	char		*tmp;
	char		*buff;
	ssize_t		ret;
}				t_box;

/*
**   All fonction prototype
*/

int				get_next_line(int fd, char **line);
int				free_return(void **addr, int ret);
ssize_t			lentochar(const char *str, int c, int mode);
char			*join_str(char *s1, char *s2, char **tofree);
char			*next_line(char	**str);
#endif
