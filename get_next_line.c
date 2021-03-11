
#include "get_next_line.h"

void	print_details(size_t len, char *str, const char *name)
{
	len++;
	printf("[%s][%p]Details (%ld): \n[", name, str, len);
	while (len > 0)
	{
		if (*str >= ' ' && *str < '~')
		{
			printf("%c", *str);
		}
		else
		{
			printf("\\%d", *str);
		}
		str++;
		len--;
		if (len > 0)
		{
			printf("");
		}
	}
	printf("] END_DETAILS\n");
}

/*
**   @param  `fd`      The file descriptor.
**   @param  `**line`
**   @param  `box`:
**     `*tmp`         .
**     `*buff`        .
**     `readRet`      .
**
**   @return L_READ (1), EO_FILE (0).
**   ERROR (-1).
*/
int		get_next_line(int fd, char **line)
{
	static t_box	box;

// P_INT(fd);
	box.readRet = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (ERROR);
	if (!(box.buff = (char*)malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	box.buff[BUFFER_SIZE] = '\0';
	while (!(lenStr(box.buff, '\n', 2)) && box.readRet)
	{
		if ((box.readRet = read(fd, box.buff, BUFFER_SIZE)) == (ssize_t)ERROR)
			return (freeRetun((void*)&box.buff, ERROR));
		box.buff[box.readRet] = '\0';
		if (!(box.tmp[fd] = joinStr(box.tmp[fd], box.buff, &box.tmp[fd])))
			return (freeRetun((void*)&box.buff, ERROR));
	}
	box.buff[0] = '\0';
	free(box.buff);
	box.buff = NULL;
	printf("tmp: |%s|", box.tmp[fd]);
	if(!(lenStr(box.tmp[fd], '\n', 2)))
	{
		*line = joinStr(box.tmp[fd], NULL, &box.tmp[fd]);
		box.eof[fd] = TRUE;
		return (EO_FILE);
	}
	if (!(*line = nextLine(&box.tmp[fd])))
		return (ERROR);
	return (L_READ);
}