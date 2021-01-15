/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/15 12:53:13 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *s1;

	s1 = s;
	if (n)
		while (n--)
			s1[n] = 0;
}

/*
**	eol_len
**
**	If len == 0, the fonction will return the number of characters that
**	precede the '\n'.	If len == 1, the fonction will return the number
**	of characters that precede the '\0'
**
**	Return :
		The number of characters
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
		while (s[i])
			i++;
	return (i);
}

/*
**	md_cpydata
**
**	The function will copy the `len` number of characters of the string
**	from `src` to `dest` starting at the `start` byte.
**	
**	Return :
**		1 = Success
**		0 = Error
*/

size_t	md_cpydata(const char *src, char *dest, size_t start, size_t len)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = eol_len(src, 1);
	dest_len = eol_len(dest, 1);
	if (src_len > dest_len || start > dest_len || len > dest_len)
		return (0);
	if (!(dest += start))
		return (0);
	while (*src && *dest && --len)
	{
		*dest = *src;
		dest++;
		src++;
	}
	if (++dest)
		*dest = '\0';
	return (1);
}
