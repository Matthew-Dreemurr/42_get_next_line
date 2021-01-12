/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:42 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/12 17:36:04 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE__
# define __GET_NEXT_LINE__

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif

int	get_next_line(int fd, char **line);
void	ft_bzero(void *s, size_t n);
size_t	eol_len(const char *s, int len);
size_t	md_cpydata(const char *src, char * dest, size_t start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);

typedef struct	s_get_next_line
{
	size_t	index;
	size_t	len;
}				t_get_next_line;

#endif