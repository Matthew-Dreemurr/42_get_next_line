/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:15:17 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/12 17:40:25 by mhadad           ###   ########.fr       */
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
#ifdef DEBUG //TODO need to remove
	printf("GNL data :\n	gnl.index = |%lu|\n	gnl.len = |%lu|\n", gnl.index, gnl.len);
#endif
	return (0);
}
