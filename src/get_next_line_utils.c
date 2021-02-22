/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/02/22 17:33:12 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*
**   diy_strlen();
**
** DESCRIPTION
**   If `mode` == 1 Will returns the number of characters preceding `c`
**    and itself.
**   If `mode` == 2 Will count the `len` until reached the `c`.
**
** PARAMETERS
**   @param `c`     The caratere we're looking for.
**   @param `str`   The srting we're looking for the `c` caracter.
**   @param `mode`  The count type.
**
** RETURN
**   `len`
**   -1 =   NULL string
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
**   ();
**
** DESCRIPTION
**   Will free the adresse pointed by `addr` and return `ret`.
**
** PARAMETERS
**   @param `addr`  Pointer to adresse.
**   @param `ret`   What we will return.
**
** RETURN
**   `ret`.
**
*/

int		ret_free(char **addr, int ret)
{
	free(*addr);
	return (ret);
}