/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/02/22 18:52:32 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*
**   If `mode` == 1 Will returns the number of characters preceding `c`
**   and itself.   If `mode` == 2 Will count the `len` until reached the `c`.
**
**   @param `str`   The srting we're looking for the `c` caracter.
**   @param `c`     The caratere we're looking for.
**   @param `mode`  The count type.
**
**   @return `len` or -1 if NULL string.
*/
ssize_t		diy_strlen(char *str, char c, int mode)
{
	ssize_t	len;

	len = -1;
	if (!str)
		return (-1);
	if (mode == 1)
	{
		(void)c;
		while (str[++len])
			;
		return (len);
	}
	else if (mode == 2)
	{
		while (str[++len])
			if (str[len] == c)
				return (++len);
		if (str[len] == c)
			return (++len);
		return (0);
	}
		return (0);
}

/*
**
**   Will free the adresse pointed by `addr` and return `ret`.
**
**   @param `addr`  Pointer to adresse.
**   @param `ret`   What we will return.
**
**   @return `ret`.
*/
int		ret_free(char **addr, int ret)
{
	free(*addr);
	return (ret);
}

/*
**   .
**
**   @param `dest`  .
**   @param `s1`    .
**   @param `s2`    .
*/
int		joinstr(char **dest, char *s1, char *s2)
{
	ssize_t	len_s1;
	ssize_t	len_s2;

	len_s1 = diy_strlen(s1, '\0', 2);
	len_s2 = diy_strlen(s1, '\0', 2);
}