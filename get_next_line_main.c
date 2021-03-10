
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>

# define NUM_FD 3

int	main(int argc, char const *argv[])
{
	int		ret[NUM_FD];
	int		fd[NUM_FD];
	char	*line[NUM_FD];

	ssize_t	i;

	if (argc < 1 || argc > 2)
		return (1);
	i = 0;
	while (i < NUM_FD)
	{
		fd[i] = open(argv[1], O_RDONLY);
		if (fd[i] < 0)
			fd[i] = 0;
		i++;
	}
	while (1)
	{
		i = -1;
		while (i < NUM_FD)
		{
			ret[i] = get_next_line(fd[i], &line[i]);
			printf("[fd %ld]ret %d | '%s'\n", i, ret[i], line[i]);
			free(line[i]);
			if (ret[i] <= 0)
			{
				i++;
				continue ;
			}
			i++;
			if (ret[NUM_FD] <= 0)
				break ;
		}
		if (ret[NUM_FD] <= 0)
			break ;
	}
	return (0);
}