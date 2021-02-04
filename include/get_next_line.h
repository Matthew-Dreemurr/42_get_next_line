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
**   All fonction prototype
*/

int		get_next_line(int fd, char **line);
size_t	eol_len(const char *s, int set);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
void	*lstcheck_fd(t_gnl list);

#endif

typedef struct s_gnl
{
	char	*str;
	ssize_t	read_ret;
	void	*next;
}				t_gnl;