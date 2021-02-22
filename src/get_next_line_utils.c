/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/02/22 23:42:33 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*
**   If `mode` == 1 Will return `len` of the string and will ignore `c`.
**   If `mode` == 2 Will return the number of characters preceding `c` and itself.
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
**   Will contanenate `s1` en `s2`.
**
**   @param `dest`  The destination will overwrite by the concatenation
**   of s1 en s2.
**   @param `s1`    .
**   @param `s2`    .
**
**   @return  1 or -1 if malloc fail.
*///TODO free the dest
int		joinstr(char **dest, char *s1, char *s2)
{
	ssize_t	l_s1;
	ssize_t	l_s2;

	l_s1 = diy_strlen(s1, '\0', 1);
	l_s2 = diy_strlen(s2, '\0', 1);
	if (!(dest = malloc(l_s1 + l_s2 + 1)))
		return (-1);
	*dest[l_s1 + l_s2] = '\0';
	while (--l_s2)
		*dest[l_s1 + l_s2] = s2[l_s2];
	while (--l_s1)
		*dest[l_s1] = s1[l_s1];
	return (1);
}