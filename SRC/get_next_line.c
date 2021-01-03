/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/03 09:58:45 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#ifdef DEBUG
# include <stdio.h>
#endif

int	get_next_line(int fd, char **line)
{
	char					*buff;
	static t_get_next_line	gnl;

	if (!(line))
		return (-1);
	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	read(fd, buff, BUFFER_SIZE);
	gnl.len += EOL_len(buff, 0);
	*line = ft_substr(buff, gnl.index, gnl.len);
	gnl.index += gnl.len;
	free(buff);
#ifdef DEBUG
	printf("GNL data :\n	gnl.index = |%lu|\n	gnl.len = |%lu|\n", gnl.index, gnl.len);
#endif
	return (0);
}
