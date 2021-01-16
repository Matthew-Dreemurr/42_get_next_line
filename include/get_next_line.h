/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:42 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/16 16:05:28 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE__
# define __GET_NEXT_LINE__

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/*
**   get_next_line return :
**      A line has been read =   LRD
**      End of line =            EOF
**      Error =	                 ERROR
*/

#define LRD 1
#define EOF 0
#define ERROR -1

int		get_next_line(int fd, char **line);
size_t	eol_len(const char *s, int len);

/*
**   struct gnl :
**      index :
**      len :
**      ret_read :
*/

typedef struct	s_gnl
{
	size_t	index;
	size_t	len;
	ssize_t		ret_read;
}				t_gnl;

#endif