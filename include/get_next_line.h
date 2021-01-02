/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:42 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/02 20:14:52 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE__
# define __GET_NEXT_LINE__

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif

#ifndef TXT
# define TXT "NOPE"
#endif

int	get_next_line(int fd, char **line);
void	ft_bzero(void *s, size_t n);
#endif