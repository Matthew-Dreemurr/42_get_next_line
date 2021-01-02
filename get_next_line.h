/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:42 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/02 15:47:33 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE__
# define __GET_NET_LINE__

#include <stdlib.h>
#include <unistd.h>

int	get_next_line(int fd, char **line);
#endif