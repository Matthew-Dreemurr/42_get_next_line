/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/01 14:56:34 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*
**   If `mode` == 1 Will return `len` of the string and will ignore `c`.
**   If `mode` == 2 Will return the number of characters preceding `c`.
**
**   @param `str`   The srting we're looking for the `c` caracter.
**   @param `c`     The caratere we're looking for.
**   @param `mode`  The count type.
**
**   @return `len` or -1 if NULL string.
*/
ssize_t		diyStrLen(char *str, char c, int mode)
{
	ssize_t	len;

	len = -1;
	if (!str)
		return (0);
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
				return (len);
//		if (str[len] == c)
//			return (++len);
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
int		retFree(char **addr, int ret)
{
	free(*addr);
	return (ret);
}

/*
**   Will contanenate `dest` en `s1` (malloc).
**
**   @param `dest`  The destination.
**   @param `s1`    The string to add @ `dest`.
**
**   @return  1 or -1 if malloc fail.
*/
char	*joinStr(char *dest, char *s1)
{
	char	*ret;
	ssize_t	lS1;
	ssize_t	lDest;

	lS1 = diyStrLen(s1, '\0', 1);
	if ((lDest = diyStrLen(dest, '\0', 1)) == -1)
		lDest = 0;
	if (!(ret = (char*)malloc(lS1 + lDest + 1)))
		return (NULL);
	ret[lS1 + lDest] = '\0';
	while (--lS1 >= 0)
		ret[lS1 + lDest] = s1[lS1];
	while (--lDest >= 0)
		ret[lDest] = (dest)[lDest];
	//free(*dest);
#ifdef DEBUG
	printf("======joinStr dest: \n|%s|\n\n", dest);
	printf("======joinStr s1: \n|%s|\n\n", s1);
#endif
#ifdef DEBUG
	printf("======joinStr ret: \n|%s|\n\n", ret);
#endif
	return (ret);
}

/*
**   (malloc)
**
**   @param `tmp`
**
**   @return  if malloc fail / `tmp` = NULL.
*/
char	*tmpClean(char *tmp)
{
	char	*ret;
	ssize_t	toSkip;
	ssize_t	len;

	len = diyStrLen(tmp, '\0', 1);
	toSkip = diyStrLen(tmp, '\n', 2);
	toSkip++;
	if (!(ret = (char*)malloc(len - toSkip + 1)))
		return (NULL);
	len -= toSkip;
	ret[len] = '\0';
	while ((tmp)[++toSkip])
	{
		*ret = (tmp)[toSkip];
		ret++;
	}
#ifdef DEBUG
	printf("======tmpClean ret: \n|%s|\n", ret);
#endif
	return (ret);
}

/*
**   Will return a string of all character preceding '\n' (malloc).
**
**
**   @param `tmp`
*/
char	*retNextLine(char *tmp)
{
	char	*ret;
	ssize_t	len;

	len = diyStrLen(tmp, '\n', 2);
	if (!(ret = (char*)malloc(len + 1)))
		return (NULL);
	ret[len] = '\0';
	//free(*tmp);
	while (--len >= 0 && (tmp)[len])
		ret[len] = (tmp)[len];
#ifdef DEBUG
	printf("======retNextLine ret: \n|%s|\n", ret);
#endif
	return (ret);
}