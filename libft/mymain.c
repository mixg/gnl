#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		read_byte(const int fd, char **line);

/*int		main(int gc, char **gv)
{
	int		fd;
	char	**line = NULL;

	if (gc < 2)
	{
		printf("Enter file.\n");
			return (0);
	}
	fd = open(gv[1], O_RDONLY);
	while (read_byte(fd, line))
		printf("line: %s", *line);
	return (0);
}
*/
/*
int		main(int gc, char **gv)
{
	int		fd;
	char	*list;
	int		i;

	if (gc < 2)
	{
		printf("Enter file.\n");
			return (0);
	}
	fd = open(gv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	i = 1;
	printf("FILE: %s\n", gv[1]);
	while (get_next_line(fd, &list) == 1)
	{
		printf("line: %d %s\n", i, list);
		i++;
	}
	return (0);
}
*/

int		main(int gc, char **gv)
{
	int	 i, j, fd;
	char	*line;

	if (gc < 2){
		printf("Enter a file.\n");
		return (0);
	}
	i = 1;
	while (gv[i])
	{
		fd = open(gv[i], O_RDONLY);
		j = 0;
		printf("fd: %d\n", fd);
		while ((get_next_line(fd, &line))){
			printf("LINE %d: %s\n", j, line);
			j++;
		}
		i++;
	}
	close(fd);
	return (0);
}
