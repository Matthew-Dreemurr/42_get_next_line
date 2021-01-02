/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/02 20:15:36 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	get_next_line(int fd, char **line)
{
	(void)fd;
	if (!(line))
		return (0);
	*line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	ft_bzero(*line, BUFFER_SIZE + 1);
	read(fd, *line, BUFFER_SIZE);
	return (0);
}
