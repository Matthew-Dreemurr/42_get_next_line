/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/16 12:49:20 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*
**   eol_len();
**
**   If len == 0, the fonction will return the number of characters that
**   precede the '\n'.	If len == 1, the fonction will return the number
**   of characters that precede the '\0'
**
**   Return :
**      The number of characters
*/

//TODO need to proterc NULL string
size_t	eol_len(const char *s, int len)
{
	size_t	i;

	i = 0;
	if (!len)
		while (s[i] && s[i] != '\n')
			i++;
	else
		while (s[i] != '\0')
			i++;
	return (i);
}
