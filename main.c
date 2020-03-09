#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int        main(int ac, char **av)
{
    int        fd;
    int        ret;
    char    *line;
	int		i;

	i = 1;
    fd = (ac == 1) ? 0 : open(av[1], O_RDONLY);
    ret = 0;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
//		dprintf(1, "Tour #%d\n", i);
        printf("%d : %s\n",ret, line);
        free(line);
		i++;
    }
//	while (1)
//	{
//	}
    printf("%d : %s\n",ret, line);
//	printf("i :%d\n", i);
    free(line);
    close(fd);
    return (0);
}
