/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:42 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/25 16:38:38 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE__
# define __GET_NEXT_LINE__

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif

/*
**   A line has been read   L_READ
**   End of line            EO_FILE
**   Error                  ERROR
*/
//TODO RENAME 
#define L_READ ((int)1)
#define EO_FILE ((int)0)
#define ERROR ((int)-1)

/*
**   All fonction prototype
*/

int		get_next_line(int fd, char **line);
size_t	eol_len(const char *s, int bool);
char	*ft_strjoin(char  *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);


/*
**   struct gnl
**      len :
**      ret_read : Use to save the return form the read(); fonction
*/

typedef struct	s_gnl
{
//
	size_t		len;
	ssize_t		ret_read;
}				t_gnl;

#endif