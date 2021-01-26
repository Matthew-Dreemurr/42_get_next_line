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
**   get_next_line return :
**      A line has been read =   LRD
**      End of line =            EOF
**      Error =	                 ERROR
*/

#define LRD ((int)1)
#define EOFL ((int)0)
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